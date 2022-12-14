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
        int n, k; cin >> n >> k;
        vector<int> p(n), c(n);
        vector<vector<int>> way(n);
        for(int i = 1; i < n; ++i){
            cin >> p[i]; --p[i];

            way[p[i]].push_back(i);
        }
        for(int i = 0; i < n; ++i){
            cin >> c[i];
        }

        auto sol = [&](auto&&self, int x, int pr, int v)->pair<int, int>{
            int lc = (int)way[x].size();
            if(!lc){
                return {v * c[x], (v + 1) * c[x]};
            }

            int lv = v / lc;
            vector<pair<int, int>> ldp;
            for(auto&nxt:way[x]) if(nxt != pr){
                ldp.push_back(self(self, nxt, x, lv));
            }

            if(v % lc == 0){
                int sum = 0, mx = 0;

                for(auto&i:ldp){
                    sum += i.first;
                    ma(mx, i.second - i.first);
                }

                return {v * c[x] + sum, (v + 1) * c[x] + sum + mx};
            }
            else{
                int sum = 0;
                vector<int> srt;

                for(auto&i:ldp){
                    sum += i.first;
                    srt.push_back(i.second - i.first);
                }

                pair<int, int> rv = {v * c[x] + sum, (v + 1) * c[x] + sum};

                sort(srt.begin(), srt.end());
                reverse(srt.begin(), srt.end());

                for(int i = 0; i < v % lc; ++i){
                    rv.first += srt[i], rv.second += srt[i];
                }
                rv.second += srt[v % lc];

                return rv;
            }
        };

        cout << sol(sol, 0, -1, k).first << '\n';
    }
    
    return 0;
}