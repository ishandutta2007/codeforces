#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
long double GX(long double k,long double b,long double k2,long double b2){
    return (b2 - b) / (k - k2);
}
vector<pair<long double,long double>> G;
vector<pair<long double,long double>> CHT;
void update(long double k,long double b){
    G.push_back({k,b});
    while(CHT.size() > 0){
        pair<long double,long double> y = G[CHT[CHT.size() - 1].second];
        long double x = GX(k,b,y.first,y.second);
        if(x <= CHT[CHT.size() - 1].first){
            CHT.pop_back();
            continue;
        }
        CHT.push_back({x,G.size() - 1});
        break;
    }
    if(CHT.size() == 0){
        CHT.push_back({- 1e18,G.size() - 1});
    }
}
long long get_ans(long double x){
    int l = 0,r = CHT.size();
    while(l + 1 < r){
        int m = (l + r) / 2;
        if(CHT[m].first > x){
            r = m;
        }
        else{
            l = m;
        }
    }
    int pos = CHT[l].second;
    return G[pos].first * x + G[pos].second;
}
signed main(){
   int n;
   cin >> n;
   vector<pair<long long,long long>> a(n);
   for(int i = 0;i < n;i++){
        cin >> a[i].first;
   }
   for(int i =0;i < n;i++){
        cin >> a[i].second;
   }
   vector<long long> dp(n + 1,0);
   dp[1] = 0;
   update(a[0].second,dp[1]);
   for(int i = 2;i <= n;i++){
        dp[i] = 1e18;
        dp[i] = min(dp[i],get_ans(a[i - 1].first));
        update(a[i - 1].second,dp[i]);
   }
   cout << dp[n];
}