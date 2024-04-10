#include<bits/stdc++.h>
#include<chrono>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
const int mn=3010;
mt19937 rng(time(0));
vector<int> k[mn];
const ll p=1e9+7,q=1e9+9;
bool s[mn],fail[mn];
ll dp[mn][mn];
unordered_set<ll> ex[mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>s[i];
    }
    for(i=4;i<=n;i++){
        fail[i]=(!s[i-3]&&!s[i-2]&&s[i-1]&&s[i])||
                (!s[i-3]&&s[i-2]&&!s[i-1]&&s[i])||
                (s[i-3]&&s[i-2]&&s[i-1]);
    }
    for(i=1;i<=n;i++){
        dp[i][i-1]=1;
        for(j=i;j<=n;j++){
            dp[i][j]+=dp[i][j-1];
            if(j-i>=1)dp[i][j]+=dp[i][j-2];
            if(j-i>=2)dp[i][j]+=dp[i][j-3];
            if(j-i>=3&&!fail[j])dp[i][j]+=dp[i][j-4];
            dp[i][j]%=mod;
        }
    }
    ll po=rng(),b=rng(),ans=0;
    for(i=1;i<=n;i++){
        pll cur={0,0};
        for(j=i;j;j--){
            cur={(cur.first*po+s[j]+b)%p,(cur.second*po+s[j]+b)%q};
            if(ex[i-j].find((cur.first<<32)|cur.second)!=ex[i-j].end())continue;
            else ex[i-j].insert((cur.first<<32)|cur.second);
            ans+=dp[j][i];
            ans%=mod;
        }
        if(ans<0)ans+=mod;
        cout<<ans<<"\n";
    }
}