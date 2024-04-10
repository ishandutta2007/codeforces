#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int q; cin >> q;
    vector<pair<int, int>> val(q + 4);
    int x, y; cin >> x >> y;
    val[0] = {x, y};
    vector<vector<int>> pr(q + 4, vector<int>(20));
    for(int i = 1; i <= q; ++i){
        int que; cin >> que;
        if(que == 1){
            int up; cin >> up;
            pr[i][0] = up;
            cin >> x >> y;
            val[i] = {x, y};
            for(int j = 1; j < 20; ++j){
                pr[i][j] = pr[pr[i][j - 1]][j - 1];
            }
        }
        else{
            cin >> x >> y;
            int ans = 0, ans2 = 0;
            while(y && val[x].first){
                int now = x;
                for(int j = 19; j >= 0; --j){
                    if(val[pr[now][j]].first){
                        now = pr[now][j];
                    }
                }
                int use = min(val[now].first, y);
                ans += use * val[now].second;
                ans2 += use;
                val[now].first -= use;
                y -= use;
            }
            cout << ans2 << ' ' << ans << '\n';
            cout.flush();
        }
    }
    return 0;
}