#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e6+10;
ll seg[mn*4],laz[mn*4];
pii a[mn];
int b[mn];
vector<pii>mon[mn];
void prop(int x){
    seg[x]+=laz[x];
    if(x*2+1<mn*4){
        laz[x*2]+=laz[x];
        laz[x*2+1]+=laz[x];
    }
    laz[x]=0;
}
void eval(int x){
    prop(x*2),prop(x*2+1);
    seg[x]=max(seg[x*2],seg[x*2+1]);
}
#define mid ((l+r)>>1)
void upd(int x,int l,int r,int a,int b,ll c){
    if(l==a&&r==b)laz[x]+=c;
    else{
        prop(x);
        if(b<=mid)upd(x*2,l,mid,a,b,c);
        else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
        else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
        eval(x);
    }
}
int main()
{
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0;i<n;i++)scanf("%d%d",&a[i].first,&a[i].second);
    sort(a,a+n);
    for(int i=n-2;i>=0;i--)a[i].second=min(a[i].second,a[i+1].second);
    memset(b,0x3f,sizeof(b));
    for(int i=0;i<m;i++){
        int k,kk;
        scanf("%d%d",&k,&kk);
        b[k]=min(b[k],kk);
    }
    for(int i=0;i<p;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        mon[y].push_back({x,z});
    }
    for(int i=0;i<n;i++){
        if(i==0||a[i].first!=a[i-1].first)upd(1,1,mn,i?(a[i-1].first+1):1,a[i].first,-a[i].second);
    }
    upd(1,1,mn,a[n-1].first+1,mn,-0x3f3f3f3f3f3f3f3f);
    ll ans=-0x3f3f3f3f3f3f3f3f;
    for(int i=0;i<mn;i++){
        if(b[i]!=0x3f3f3f3f){
            prop(1);
            ans=max(ans,seg[1]-b[i]);
        }
        for(pii p:mon[i]){
            if(p.first+1>a[n-1].first)continue;
            upd(1,1,mn,p.first+1,mn,p.second);
        }
    }
    printf("%lld",ans);
}