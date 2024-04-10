#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
typedef unsigned long long ll;
typedef pair<ll,ll>pll;
const int mn=1e6+10;
ll a[mn*2];
int nxt[mn*2],dis[mn*2],at[mn*2];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    ll tot=0;
    for(int i=1;i<=n;i++)scanf("%lld",a+i),a[n+i]=a[i],tot+=a[i];
    while(q--){
        ll x;
        scanf("%lld",&x);
        if(x>=tot){
            printf("1\n");
            continue;
        }
        ll sum=a[1];
        for(int i=1,j=1;i<=n;sum-=a[i++]){
            while(sum<=x)sum+=a[++j];
            nxt[i-1]=j-1;
            nxt[i-1+n]=j-1+n;
        }
        iota(at,at+mn,0);
        memset(dis,0,sizeof(dis));
        int st=0;
        for(int i=1;i<n;i++)if(nxt[i]-i<nxt[st]-st)st=i;
        int ans=0x3f3f3f3f;
        for(int i=st;i<=nxt[st];i++){
            int k=0;
            for(int j=i%n;j<i%n+n;j=nxt[j],k++);
            ans=min(ans,k);
        }
        printf("%d\n",ans);
    }
}