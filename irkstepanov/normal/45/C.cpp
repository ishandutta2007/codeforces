#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct datum {
    int cost;
    int a, b;
    bool operator<(const datum& other) const {
        if (cost != other.cost) {
            return cost < other.cost;
        }
        return a < other.a;
    }
};

vector<bool> alive;
vector<int> lf, rg;
set<datum> q;
vector<int> c;
string s;

void del(int i) {
    alive[i] = false;
    int a = lf[i];
    int j = rg[i];
    alive[j] = false;
    int b = rg[j];
    if (a != -1) {
        rg[a] = b;
    }
    if (b != -1) {
        lf[b] = a;
    }
    if (a != -1 && s[a] != s[i]) {
        q.erase({abs(c[a] - c[i]), a, i});
    }
    if (b != -1 && s[b] != s[j]) {
        q.erase({abs(c[b] - c[j]), j, b});
    }
    if (a != -1 && b != -1 && s[a] != s[b]) {
        q.insert({abs(c[a] - c[b]), a, b});
    }
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cin >> s;

    c.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    alive.assign(n, true);
    lf.resize(n);
    rg.resize(n);
    for (int i = 0; i < n; ++i) {
        lf[i] = i - 1;
        if (lf[i] < 0) {
            lf[i] = -1;
        }
        rg[i] = i + 1;
        if (rg[i] >= n) {
            rg[i] = -1;
        }
    }

    
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] != s[i + 1]) {
            q.insert({abs(c[i] - c[i + 1]), i, i + 1});
        }
    }

    vector<pii> ans;

    while (!q.empty()) {
        datum d = *q.begin();
        q.erase(q.begin());
        ans.pb({min(d.a, d.b), max(d.a, d.b)});
        int i = d.a, j = d.b;
        del(i);
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }

}