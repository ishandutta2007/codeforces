#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<vector<ll>> pref;

int n;
ll get_sum(int x1, int y1, int x2, int y2) {
    if(x1 < 0 || y1 < 0 || x2 >= 2 * n || y2 >= 2 * n || x1 > x2 || y1 > y2) return 0;
    ll res = pref[x2 + 1][y2 + 1];
    res += pref[x1][y1];
    res -= pref[x1][y2 + 1];
    res -= pref[x2 + 1][y1];
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        vector<vector<ll>> a(2 * n, vector<ll>(2 * n));
        ll ans = 0;
        for(int i = 0; i < 2 * n; i++) {
            for(int j = 0; j < 2 * n; j++) {
                cin >> a[i][j];
                if(i >= n && j >= n) {
                    ans += a[i][j];
                    a[i][j] = 0;
                }
            }
        }
        pref.assign(2 * n + 1, vector<ll>(2 * n + 1, 0));
        for(int i = 1; i <= 2 * n; i++) {
            for(int j = 1; j <= 2 * n; j++) {
                ll here = pref[i][j - 1] + pref[i - 1][j] - pref[i - 1][j - 1];
                here += a[i - 1][j - 1];
                pref[i][j] = here;
            }
        }
        /*bool ok = true;
        ll can = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                can += a[i][j];
            }
        }*/
        ll mn = 1e18;
        int e = 2 * n - 1;
        /*mn = min(mn, get_sum(e, 0, e, n - 1));
        mn = min(mn, get_sum(n, 0, n, n - 1));
        mn = min(mn, get_sum(n - 1, n, n - 1, e));
        mn = min(mn, get_sum(0, n, 0, e));
        mn = min(mn, get_sum(n, 0, e, 0));
        mn = min(mn, get_sum(n, n - 1, e, n - 1));
        mn = min(mn, get_sum(0, n, n - 1, n));
        mn = min(mn, get_sum(0, e, n - 1, e));*/
        mn = min(mn, a[n - 1][n]);
        mn = min(mn, a[n][n - 1]);
        mn = min(mn, a[n][0]);
        mn = min(mn, a[0][n]);
        mn = min(mn, a[e][0]);
        mn = min(mn, a[0][e]);
        mn = min(mn, a[e][n - 1]);
        mn = min(mn, a[n - 1][e]);
        cout << ans + mn << '\n';
    }

}