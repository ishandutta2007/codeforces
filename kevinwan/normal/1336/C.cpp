#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<int,ll>pil;
typedef pair<ll,ll>pll;
const int mn=3e3+10;
const ll mod=998244353;
ll dp[mn][mn];
inline bool eq(char a,char b){if(a=='#'||b=='#')return 1;return a==b;}
int main(){
    string s,t;
    cin>>s>>t;
    reverse(s.begin(),s.end());
    int n=s.size(),m=t.size();
    for(int i=0;i<n-m;i++)t.push_back('#');
    for(int i=0;i<=n-m;i++)dp[0][i]=1;
    for(int len=0;len<n;len++){
        for(int i=0;i<=len;i++){
            int j=len-i;
            if(eq(s[len],t[i]))dp[i+1][j]+=dp[i][j],dp[i+1][j]%=mod;
            if(eq(s[len],t[n-j-1]))dp[i][j+1]+=dp[i][j],dp[i][j+1]%=mod;
        }
    }
    ll ans=0;
    for(int i=0;i<=n;i++)ans+=dp[i][n-i],ans%=mod;
    printf("%lld",ans);
}