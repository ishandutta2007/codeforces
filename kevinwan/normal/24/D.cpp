#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef __int128 lll;
const ll mod=1e9+7;
const int mn=1e3+10;
double a[mn],b[mn];
double dp[mn][mn];
int n,m;
void hail(double ans[mn],double inp[mn]){
    memcpy(a,inp,sizeof(a));
    int ct=100;
    while(ct--){
        b[1]=(a[1]+a[2]+inp[1])/3+1;
        b[m]=(a[m]+a[m-1]+inp[m])/3+1;
        for(int i=2;i<m;i++)b[i]=(a[i-1]+a[i]+a[i+1]+inp[i])*.25+1;
        memcpy(a,b,sizeof(a));
    }
    memcpy(ans,a,sizeof(a));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b;
    cin>>n>>m>>a>>b;
    if(m==1){printf("%.20lf",2.*(n-a));return 0;}
    for(int i=n-1;i>=1;i--)hail(dp[i],dp[i+1]);
    printf("%.20lf",dp[a][b]);
}