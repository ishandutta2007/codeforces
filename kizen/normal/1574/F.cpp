#include <bits/stdc++.h>
#define int long long
#define mi(x, y) (x = min(x, y))
#define ma(x, y) (x = max(x, y))
using namespace std;

const int mod = 998244353;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    vector<set<int>> way(k), wayb(k);
    vector<int> chk(k);
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        int lst = -1;
        while(x--){
            int now; cin >> now; --now;
            if(lst != -1){
                way[lst].insert(now);
                wayb[now].insert(lst);
            }
            lst = now;
        }
    }
    vector<int> use;
    int cnt, tail;
    auto dfs = [&](auto&&self, int x)->void{
        chk[x] = 1; ++cnt;
        if((int)way[x].size() >= 2 || (int)wayb[x].size() >= 2){
            cnt = -(int)1e9;
        }
        if((int)way[x].size() == 0) tail = 1;
        for(auto&nxt:way[x]){
            if(!chk[nxt]){
                self(self, nxt);
            }
        }
        for(auto&nxt:wayb[x]){
            if(!chk[nxt]){
                self(self, nxt);
            }
        }
    };
    for(int i = 0; i < k; ++i){
        if(chk[i]) continue;
        cnt = 0; tail = 0;
        dfs(dfs, i);
        if(cnt >= 0 && tail){
            use.push_back(cnt);
        }
    }
    vector<int> dp(m + 1);
    sort(use.begin(), use.end());
    vector<pair<int, int>> up;
    for(int i = 0; i < (int)use.size(); ++i){
        int j = i;
        while(j + 1 < (int)use.size() && use[i] == use[j + 1]) ++j;
        up.push_back({use[i], j - i + 1});
        i = j;
    }
    dp[0] = 1;
    for(int i = 1; i <= m; ++i){
        for(auto&j:up){
            if(i - j.first >= 0){
                dp[i] = (dp[i] + dp[i - j.first] * j.second) % mod;
            }
        }
    }
    cout << dp[m];
    return 0;
}