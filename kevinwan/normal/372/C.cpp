#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
int a[mn],b[mn],t[mn];
ll dp[mn],nxt[mn];
int main(){
    int n,m,d,i,j;
    scanf("%d%d%d",&n,&m,&d);
    for(i=1;i<=m;i++)scanf("%d%d%d",a+i,b+i,t+i);
    deque<pair<ll,int>>q;
    int cr=1,l,r;
    for(i=1;i<=m;i++){
        cr=1;
        for(j=1;j<=n;j++) {
            l = max(1LL,j-1LL*d*(t[i]-t[i-1]));
            r=min(0LL+n,j+1LL*d*(t[i]-t[i-1]));
            for(;cr<=r;cr++){
                while(q.size()&&q.back().first<=dp[cr])q.pop_back();
                q.push_back({dp[cr],cr});
            }
            while(q.size()&&q.front().second<l)q.pop_front();
            nxt[j]=q.front().first+b[i]-1LL*abs(a[i]-j);
        }
        memcpy(dp,nxt,sizeof(dp));
        q.clear();
    }
    ll ans=0xc0c0c0c0c0c0c0c0;
    for(j=1;j<=n;j++)ans=max(ans,dp[j]);
    printf("%lld",ans);
}