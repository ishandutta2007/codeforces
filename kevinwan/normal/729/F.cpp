#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=998244353;
const int mn=4e3+10;
int dp[mn][100][100][2];
int v[mn],sv[mn];
int n;
ll solve(int a,int b,int c,bool d){
    if(a+a+b>n)return d?-1e13:1e13;
    else if(a+a+b+c>n)return 0;
    else if(dp[a][b][c][d]!=0x3f3f3f3f)return dp[a][b][c][d];
    ll ans;
    if(!d){
        ans=max(sv[a+c]-sv[a]+solve(a+b,c-b,c,1),sv[a+c+1]-sv[a]+solve(a+b,c-b+1,c+1,1));
        assert(ans>-0x3f3f3f3f&&ans<0x3f3f3f3f);
    }
    else{
        ans=min(-sv[n-a]+sv[n-a-c]+solve(a+b,c-b,c,0),-sv[n-a]+((n-a-c-1<0)?0:sv[n-a-c-1])+solve(a+b,c-b+1,c+1,0));
        assert(ans>-0x3f3f3f3f&&ans<0x3f3f3f3f);
    }
    return dp[a][b][c][d]=ans;
}
int main(){
    //freopen("hail.in","r",stdin);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n+1;i++)sv[i]=sv[i-1]+v[i];
    memset(dp,0x3f,sizeof(dp));
    printf("%lld",solve(0,0,1,0));
}