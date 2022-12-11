#include <bits/stdc++.h>

using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pll;

vector<int> operator+(vector<int> a, vector<int> b)
{
    while (sz(a) < sz(b)) {
        a.pb(0);
    }
    while (sz(b) < sz(a)) {
        b.pb(0);
    }
    int c = 0;
    vector<int> ans;
    for (int i = 0; i < sz(a); ++i) {
        c = c + a[i] + b[i];
        ans.pb(c % 10);
        c /= 10;
    }
    if (c) {
        ans.pb(c);
    }
    return ans;
}

vector<int> operator*(vector<int> a, int b)
{
    vector<int> ans;
    int c = 0;
    for (int i = 0; i < sz(a); ++i) {
        c = c + a[i] * b;
        ans.pb(c % 10);
        c /= 10;
    }
    if (c) {
        ans.pb(c);
    }
    return ans;
}

vector<vector<int> > degs(2001);

int main()
{

    //ifstream cin("input.txt");

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    degs[0] = {1};
    for (int i = 1; i <= 2000; ++i) {
        degs[i] = degs[i - 1];
        degs[i] = degs[i] * 2;
    }

    int n;
    cin >> n;

    vector<int> a(n);
    vector<char> c(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s >> a[i];
        if (s == "sell") {
            c[i] = '-';
        } else {
            c[i] = '+';
        }
    }

    vector<char> used(n, false);
    vector<int> ans = {0};

    for (int cost = 2000; cost >= 0; --cost) {
        int pos = -1;
        for (int i = 0; i < n; ++i) {
            if (c[i] == '-' && a[i] == cost && !used[i]) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            continue;
        }
        int j = -1;
        for (int i = pos - 1; i >= 0; --i) {
            if (used[i]) {
                break;
            }
            if (c[i] == '+' && a[i] == cost && !used[i]) {
                j = i;
                break;
            }
        }
        if (j == -1) {
            continue;
        }
        for (int i = j; i <= pos; ++i) {
            used[i] = true;
        }
        ans = ans + degs[cost];
    }

    for (int i = sz(ans) - 1; i >= 0; --i) {
        cout << ans[i];
    }
    cout << "\n";

}