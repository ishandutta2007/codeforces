#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

struct node {
    int to[5];
    int sum;
    node() {
        memset(to, -1, sizeof(to));
        sum = 0;
    }
};

vector<node> t;

void add(const string& s) {
    int v = 0;
    for (int i = 0; i < sz(s); ++i) {
        int c = s[i] - 'a';
        if (t[v].to[c] == -1) {
            t[v].to[c] = sz(t);
            t.pb(node());
        }
        v = t[v].to[c];
    }
    ++t[v].sum;
}

vector<string> order;

void f(string& a, const string& t, int pos) {
    if (pos == sz(t)) {
        string curr = "";
        for (int i = 0; i < sz(a); ++i) {
            if (a[i] != '-') {
                curr += a[i];
            }
        }
        order.pb(curr);
        return;
    }
    if (t[pos] == '?') {
        a[pos] = '-';
        f(a, t, pos + 1);
        for (int i = 0; i < 5; ++i) {
            a[pos] = char(i + 'a');
            f(a, t, pos + 1);
        }
    } else {
        a[pos] = t[pos];
        f(a, t, pos + 1);
    }
}

int solve(const string& s) {
    int v = 0;
    for (int i = 0; i < sz(s); ++i) {
        int c = s[i] - 'a';
        if (t[v].to[c] == -1) {
            return 0;
        }
        v = t[v].to[c];
    }
    return t[v].sum;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("input.txt");

    int n, m;
    cin >> n >> m;
    t.pb(node());

    while (n--) {
        string s;
        cin >> s;
        add(s);
    }

    while (m--) {
        string t;
        cin >> t;
        string a = t;
        f(a, t, 0);
        sort(all(order));
        order.resize(unique(all(order)) - order.begin());
        int ans = 0;
        for (string& p : order) {
            ans += solve(p);
        }
        order.clear();
        cout << ans << "\n";
    }

}