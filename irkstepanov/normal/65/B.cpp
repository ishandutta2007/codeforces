#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

const int nmin = 1000;
const int nmax = 2012;

bool valid(int a, int b) {
    int cnt = 0;
    if (a % 10 != b % 10) {
        ++cnt;
    }
    if ((a / 10) % 10 != (b / 10) % 10) {
        ++cnt;
    }
    if ((a / 100) % 10 != (b / 100) % 10) {
        ++cnt;
    }
    if (a / 1000 != b / 1000) {
        ++cnt;
    }
    return cnt <= 1;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int> > possible(n);
    for (int i = 0; i < n; ++i) {
        for (int j = nmin; j < nmax; ++j) {
            if (valid(a[i], j)) {
                possible[i].pb(j);
            }
        }
    }

    vector<vector<pii> > dp(n);
    for (int x : possible[0]) {
        dp[0].pb({x, 0});
    }
    for (int i = 1; i < n; ++i) {
        for (int y : possible[i]) {
            for (pii p : dp[i - 1]) {
                if (y >= p.first) {
                    //cout << i << " " << y << endl;
                    dp[i].pb({y, p.first});
                    break;
                }
            }
        }
    }

    if (dp[n - 1].empty()) {
        cout << "No solution\n";
        return 0;
    }
    pii p = dp[n - 1][0];
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; --i) {
        ans[i] = p.first;
        if (i == 0) {
            break;
        }
        int x = p.second;
        for (pii q : dp[i - 1]) {
            if (q.first == x) {
                p = q;
                break;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }
    
}