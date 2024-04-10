#include<bits/stdc++.h>
#ifndef LOCAL_PROJECT
#define cerr if(0)cerr
#endif
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef __int128 lll;
const lll ONE=1;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=5e3+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
const ll mod=1e9+7;
int dp[mn][mn];
int d[mn*200],s[mn],a[mn];
int main(){
#ifdef LOCAL_PROJECT
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#else
    cin.tie(0);
    cin.sync_with_stdio(0);
#endif
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0;
    for(int i=0;i<n;i++){
        memset(d,0,sizeof(d));
        memset(s,0,sizeof(s));
        for(int j=1;j<=n;j++){
            if(j>i)ans=max(ans,dp[i][j]=dp[j][i]=max({dp[i][0],d[a[j]-1],d[a[j]+1],s[a[j]%7]})+1);
            d[a[j]]=max(d[a[j]],dp[i][j]);
            s[a[j]%7]=max(s[a[j]%7],dp[i][j]);
        }
    }
    printf("%d",ans);
}