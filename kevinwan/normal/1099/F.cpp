#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef pair<int,int>pii;
const int mn=1e6+10;
ll bit[2][mn];
void up(int c,int a,ll b){for(;a<mn;a+=a&-a)bit[c][a]+=b;}
ll qu(int c,int a){ll b=0;for(;a;a-=a&-a)b+=bit[c][a];return b;}
ll bs(ll x){
    ll cur=0,sum=0;
    for(ll i=1<<19;i;i>>=1){
        if(cur+i>=mn)continue;
        if(sum+bit[0][cur+i]<=x)sum+=bit[0][cur+=i];
    }
    return cur;
}
ll rt[mn],t[mn],v[mn],l[mn],sc[mn];
vector<int>g[mn];
void dfs1(int x){
    if(rt[x]<0){sc[x]=0xc0c0c0c0c0c0c0c0;return;}
    up(0,t[x],t[x]*v[x]);
    up(1,t[x],v[x]);
    ll lim=bs(rt[x]);
    sc[x]=qu(1,lim);
    if(lim!=mn-1){sc[x]+=(rt[x]-qu(0,lim))/(lim+1);}
    ll a=0xc0c0c0c0c0c0c0c0,b=a;
    for(int y:g[x]){
        rt[y]=rt[x]-l[y]*2;
        dfs1(y);
        if(sc[y]>a)b=a,a=sc[y];
        else if(sc[y]>b)b=sc[y];
    }
    if(x==1)sc[x]=max(sc[x],a);
    else sc[x]=max(sc[x],b);
    up(0,t[x],-t[x]*v[x]);
    up(1,t[x],-v[x]);
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    ll T;
    cin>>n>>T;
    rt[1]=T;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>t[i];
    for(int i=2;i<=n;i++){
        int p;
        cin>>p>>l[i];
        g[p].push_back(i);
    }
    dfs1(1);
    printf("%lld",sc[1]);
}