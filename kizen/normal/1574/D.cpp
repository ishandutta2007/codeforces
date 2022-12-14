#include <bits/stdc++.h>
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> a(n);
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        while(x--){
            int y; cin >> y;
            a[i].push_back(y);
        }
    }
    int m; cin >> m;
    vector<vector<int>> ban(m, vector<int>(n));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> ban[i][j]; --ban[i][j];
        }
    }
    sort(ban.begin(), ban.end());
    int ans = -1;
    vector<int> ansv;
    auto go = [&](vector<int> vc){
        int pos = lower_bound(ban.begin(), ban.end(), vc) - ban.begin();
        if(pos < (int)ban.size() && ban[pos] == vc) return;
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += a[i][vc[i]];
        }
        if(sum > ans){
            ans = sum;
            ansv = vc;
        }
    };
    vector<int> top;
    for(int i = 0; i < n; ++i){
        top.push_back((int)a[i].size() - 1);
    }
    go(top);
    for(int i = 0; i < m; ++i){
        auto now = ban[i];
        for(int j = 0; j < n; ++j){
            --now[j];
            if(now[j] >= 0) go(now);
            ++now[j];
        }
    }
    for(auto&i:ansv) cout << i + 1 << ' ';
    return 0;
}