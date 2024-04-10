#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)

void solve() {
    int n,m; cin >> n >> m;
    vector<string> know(n);
    for(auto& i : know) cin >> i;
    string want; cin >> want;
    map<string,array<int,3>> mp;
    {
    int id=1;
    for(auto& i : know) {
        for(int j=0;j+2<=m;++j) {
            mp[i.substr(j,2)] = {id,j+1,j+2};
            if(j+3<=m) mp[i.substr(j,3)] = {id,j+1,j+3};
        }
        ++id;
    }
    }
    vector<array<int,3>> dp(m+1);
    for(int i=0;i<m;++i) {
        if(i==0 or dp[i][0]!=0) {
            auto transition = [&](int len) {
                if(i+len>m) return;
                auto t  = want.substr(i,len);
                if(mp.count(t)) dp[i+len] = mp[t];
            };
            transition(2),transition(3);
        }
    }
    vector<array<int,3>> ans;
    auto at = m;
    if(dp[at][0]==0) {
        cout << "-1\n";
        return;
    }
    while(at) {
        ans.push_back(dp[at]);
        at-=dp[at][2]-dp[at][1]+1;
    }
    reverse(all(ans));
    cout<< ans.size() << '\n';
    for(auto [id,l,r] : ans) {
        cout << l << ' ' << r << ' ' << id << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}