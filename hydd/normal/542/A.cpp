#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,m,cnt,num[810000];
pii tree[810000],R[810000],L[810000];
vector<int> pp[810000],qq[810000];
struct node{
    int l,r,v;
    bool operator<(const node &a) const{ return l<a.l||l==a.l;}
} p[210000],q[210000];
void add(int x,pii y){
    for (;x;x-=x&-x) tree[x]=max(tree[x],y);
}
pii query(int x){
    pii res=pii(0,0);
    for (;x<=cnt;x+=x&-x) res=max(res,tree[x]);
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        scanf("%d%d",&p[i].l,&p[i].r);
        num[++cnt]=p[i].l; num[++cnt]=p[i].r;
    }
    for (int i=1;i<=m;i++){
        scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].v);
        num[++cnt]=q[i].l; num[++cnt]=q[i].r;
    }
    sort(num+1,num+cnt+1); cnt=unique(num+1,num+cnt+1)-num-1;
    for (int i=1;i<=n;i++){
        p[i].l=lower_bound(num+1,num+cnt+1,p[i].l)-num;
        p[i].r=lower_bound(num+1,num+cnt+1,p[i].r)-num;
    }
    for (int i=1;i<=m;i++){
        q[i].l=lower_bound(num+1,num+cnt+1,q[i].l)-num;
        q[i].r=lower_bound(num+1,num+cnt+1,q[i].r)-num;
    }
    num[0]=0; num[cnt+1]=1e9+1;

    for (int i=0;i<=cnt+1;i++) L[i]=pii(0,0);
    for (int i=1;i<=n;i++) L[p[i].l]=max(L[p[i].l],pii(p[i].r,i));
    for (int i=1;i<=cnt;i++) L[i]=max(L[i-1],L[i]);

    for (int i=0;i<=cnt+1;i++) R[i]=pii(cnt+1,0);
    for (int i=1;i<=n;i++) R[p[i].r]=min(R[p[i].r],pii(p[i].l,i));
    for (int i=cnt;i>=1;i--) R[i]=min(R[i],R[i+1]);

    for (int i=1;i<=n;i++) pp[p[i].r].push_back(i);
    for (int i=1;i<=m;i++) qq[q[i].r].push_back(i);
    ll ans=0; int ll=-1,rr=-1;
    for (int i=1;i<=m;i++){
        if (1ll*(num[q[i].r]-max(num[R[q[i].r].first],num[q[i].l]))*q[i].v>ans){
            ans=1ll*(num[q[i].r]-max(num[R[q[i].r].first],num[q[i].l]))*q[i].v;
            ll=R[q[i].r].second; rr=i;
        }
        if (1ll*(min(num[q[i].r],num[L[q[i].l].first])-num[q[i].l])*q[i].v>ans){
            ans=1ll*(min(num[q[i].r],num[L[q[i].l].first])-num[q[i].l])*q[i].v;
            ll=L[q[i].l].second; rr=i;
        }
    }
    for (int i=1;i<=cnt;i++){
        for (int v:pp[i])
            add(p[v].l,pii(num[p[v].r]-num[p[v].l],v));
        for (int v:qq[i]){
            pii tmp=query(q[v].l);
            if (1ll*tmp.first*q[v].v>ans){
                ans=1ll*tmp.first*q[v].v;
                ll=tmp.second; rr=v;
            }
        }
    }
    printf("%lld\n",ans);
    if (ll!=-1) printf("%d %d\n",ll,rr);
    return 0;
}