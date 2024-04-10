#include<bits/stdc++.h>
using namespace std;
#define mid ((l+r)>>1)
typedef long long ll;
typedef long double ld;
const int mn=1210;
int l[mn],r[mn];
string s;
int dp[mn][mn];
string ans[mn][mn];
void hail(int a,int b){
    if(dp[a][b]!=-1)return;
    if(a>b){dp[a][b]=(a==b+1);return;}
    dp[a][b]=0;
    for(int i=l[a]+(!(l[a]&1));i<=r[a];i+=2){
        hail(a+1,a+(i/2));
        hail(a+i/2+1,b);
        if(dp[a+1][a+i/2]&&dp[a+i/2+1][b]){
            dp[a][b]=1;
            ans[a][b]="("+ans[a+1][a+i/2]+")"+ans[a+i/2+1][b];
            return;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d%d",l+i,r+i);
    s.resize(n*2);
    memset(dp,-1,sizeof(dp));
    hail(1,n);
    if(dp[1][n])cout<<ans[1][n];
    else cout<<"IMPOSSIBLE";
}