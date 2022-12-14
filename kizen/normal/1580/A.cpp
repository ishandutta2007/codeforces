#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        int ans = 21;
        vector<string> a(n + 1);
        for(int i = 1; i <= n; ++i){
            cin >> a[i];
            a[i] = "0" + a[i];
        }
        vector<vector<int>> pre(n + 1, vector<int>(m + 1));
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                pre[i][j] = a[i][j] - '0';
                pre[i][j] += pre[i][j - 1] + pre[i - 1][j] - pre[i - 1][j - 1];
            }
        }
        auto get = [&](int sx, int sy, int ex, int ey)->int{
            int rv = pre[ex][ey];
            rv -= pre[sx - 1][ey] + pre[ex][sy - 1];
            rv += pre[sx - 1][sy - 1];
            return rv;
        };
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                for(int x = i + 4; x <= n; ++x){
                    for(int y = j + 3; y <= m; ++y){
                        int now = get(i + 1, j + 1, x - 1, y - 1);
                        now += x - i - 1 - get(i + 1, j, x - 1, j);
                        now += y - j - 1 - get(i, j + 1, i, y - 1);
                        now += y - j - 1 - get(x, j + 1, x, y - 1);
                        if(now >= ans) break;
                        now += x - i - 1 - get(i + 1, y, x - 1, y);
                        mi(ans, now);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}