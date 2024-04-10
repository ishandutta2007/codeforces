#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int low = 0, high = n, mid;
    while(low < high){
        mid = (low + high + 1) >> 1;
        vector<vector<int>> last(n, vector<int>(k, (int)1e9));
        vector<vector<int>> pos(k);
        for(int i = n - 1; i >= 0; --i){
            if(i < n - 1) last[i] = last[i + 1];
            if(s[i] != '?'){
                last[i][s[i] - 'a'] = i;
            }
            if(i + mid <= n){
                vector<int> no;
                for(int j = 0; j < k; ++j){
                    if(last[i][j] - i < mid){
                        no.push_back(j);
                    }
                }
                if(!(int)no.size()){
                    for(int j = 0; j < k; ++j){
                        pos[j].push_back(i);
                    }
                }
                else if((int)no.size() == 1){
                    pos[no[0]].push_back(i);
                }
            }
        }
        for(int i = 0; i < k; ++i){
            reverse(pos[i].begin(), pos[i].end());
        }
        vector<int> dp(1 << k);
        for(int i = 1; i < (1 << k); ++i){
            dp[i] = (int)1e9;
            for(int j = 0; j < k; ++j){
                if(i & (1 << j)){
                    int pre = i ^ (1 << j);
                    int nxt = lower_bound(pos[j].begin(), pos[j].end(), dp[pre]) - pos[j].begin();
                    if(nxt < (int)pos[j].size()){
                        umi(dp[i], pos[j][nxt] + mid);
                    }
                }
            }
        }
        if(dp[(1 << k) - 1] != (int)1e9){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    cout << low;
    return 0;
}