#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int T;
ll N,Q;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> Q;
        vll dp(N,0);
        vll dpm(N,0);
        vll v(N);
        for(auto &x: v)cin >> x;
        dp[0]=v[0];
        for(int i = 1; i < N; i++){
            dp[i] = max({dp[i],dp[i-1],dpm[i-1]+v[i]});
            dpm[i] = max({dpm[i],dpm[i-1],dp[i-1]-v[i]});
        //    cout << i << " dp "<<dp[i]<<" dpm "<<dpm[i]<<endl;
        }
        cout << dp[N-1]<<"\n";
    }
    return 0;
}