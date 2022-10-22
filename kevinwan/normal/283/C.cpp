#include <bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
typedef long long ll;
const int mn=1e5+10;
const ll mod=1e9+7;
int nxt[310];
void die(){
    printf("0");
    exit(0);
}
ll a[mn];
bool vis[mn],st[mn];
ll dp[mn];
int main() {
    int n,q;
    ll t;
    scanf("%d%d%lld",&n,&q,&t);
    memset(st,1,sizeof(st));
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    while(q--){
        int b,c;
        scanf("%d%d",&b,&c);
        nxt[b]=c;
        st[c]=0;
    }
    for(int i=1;i<=n;i++){
        if(st[i])
        for(int x=i;x;x=nxt[x]){
            vis[x]=1;
            if(nxt[x]){
                t-=a[x];
                a[nxt[x]]+=a[x];
            }
        }
    }
    for(int i=1;i<=n;i++)if(!vis[i])die();
    if(t<0)die();
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(ll j=a[i];j<=t;j++){
            dp[j]+=dp[j-a[i]],dp[j]%=mod;;
        }
    }
    printf("%lld",dp[t]);
}