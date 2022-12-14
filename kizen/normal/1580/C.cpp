#include <bits/stdc++.h>
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

const int NS = (int)2e5 + 4;
int x[NS], y[NS];
pair<int, int> que[NS];
int to[NS], last[NS], ans2[NS], ans[NS];
int ls[700][700], fl[NS];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> que[i].first >> que[i].second;
        --que[i].second;
    }
    int B = sqrt(m);
    for(int i = 0; i < n; ++i) last[i] = m;
    for(int i = m - 1; i >= 0; --i){
        if(que[i].first == 1){
            to[i] = last[que[i].second];
        }
        else{
            last[que[i].second] = i;
        }
    }
    for(int i = 0; i < m; ++i){
        int num = que[i].second;
        long long mov = x[num] + y[num];
        if(que[i].first == 1){
            fl[num] = i;
            if(x[num] + y[num] >= B){
                long long j = i - 1;
                while(j + mov < to[i]){
                    ans2[j + x[num] + 1] += 1;
                    ans2[j + mov + 1] -= 1;
                    j += mov;
                }
                if(j + x[num] + 1 < to[i]){
                    ans2[j + x[num] + 1] += 1;
                    ans2[to[i]] -= 1;
                }
            }
            else{
                for(int j = x[num]; j < mov; ++j){
                    ++ls[mov][(i + j) % mov];
                }
            }
        }
        else{
            if(x[num] + y[num] < B){
                for(int j = x[num]; j < mov; ++j){
                    --ls[mov][(fl[num] + j) % mov];
                }
            }
        }
        for(int j = 1; j < B; ++j){
            ans[i] += ls[j][i % j];
        }
    }
    for(int i = 0; i < m; ++i){
        if(i) ans2[i] += ans2[i - 1];
        cout << ans2[i] + ans[i] << '\n';
    }
    return 0;
}