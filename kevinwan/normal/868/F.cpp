#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=1e5+10;
ll dp[mn][21];
ll v[mn];
int cnt[mn];
ll sc=0;
int cl=1,cr=0;
void go(int l,int r){
    while(cr<r)sc+=cnt[v[++cr]]++;
    while(cr>r)sc-=--cnt[v[cr--]];
    while(cl>l)sc+=cnt[v[--cl]]++;
    while(cl<l)sc-=--cnt[v[cl++]];
}
void solve(int x,int l,int r,int a,int b){
    int mid=((l+r)>>1);
    int bes=a;
    for(int i=a;i<=min(b,mid);i++){
        go(i,mid);
        ll pro=dp[i-1][x-1]+sc;
        if(pro<dp[mid][x])dp[mid][x]=pro,bes=i;
    }
    if(l!=r){
        solve(x,l,mid,a,bes);
        solve(x,mid+1,r,bes,b);
    }
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",v+i);
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=k;i++)solve(i,1,n,1,n);
    printf("%lld",dp[n][k]);
}