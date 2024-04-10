#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=3e5+10;
int n,q,A[maxn],B[maxn];

int st[maxn],lef[maxn],rig[maxn];

struct point{
  int x,y;
};

ll get(point p){
  return 1ll*abs(A[p.x]-A[p.y])*(B[p.x]+B[p.y]);
}

#define ALL(x) (x).begin(),(x).end()

vector<point>dat;

struct Querys{
  int l,r,tid;
}Q[maxn];

ll ans[maxn];

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

void chkmin(ll&x,ll y){
  if(x>y)x=y;
}
ll tag[maxn<<2];
void upd(int k,int l,int r,int ql,int qr,ll w){
  if(ql<=l&&r<=qr)return chkmin(tag[k],w);
  if(ql<=mid)upd(lson,ql,qr,w);
  if(qr>mid)upd(rson,ql,qr,w);
}
ll query(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return tag[k];
  ll res=tag[k];
  if(ql<=mid)chkmin(res,query(lson,ql,qr));
  if(qr>mid)chkmin(res,query(rson,ql,qr));
  return res;
}

int main(){
  cin>>n>>q;
  rep(i,1,n)scanf("%d%d",A+i,B+i);
  rep(i,1,q){
    scanf("%d%d",&Q[i].l,&Q[i].r);
    Q[i].tid=i;
  }
  int top=0;
  fill(rig+1,rig+n+1,n+1);
  rep(i,1,n){
    while(top&&B[st[top]]>=B[i])rig[st[top--]]=i;
    lef[i]=st[top],st[++top]=i;
  }
  dat.reserve(2*n);
  rep(i,1,n){
    if(lef[i])dat.push_back({lef[i],i});
    if(rig[i]<=n)dat.push_back({i,rig[i]});
  }
  sort(ALL(dat),[](point P,point Q){
    return P.x>Q.x;
  });
  sort(Q+1,Q+q+1,[](Querys P,Querys Q){
    return P.l>Q.l;
  });
//  for(point p:dat){
//    printf("%d %d : %lld\n",p.x,p.y,get(p));
//  }
  memset(tag,0x3f,sizeof tag);
  for(int i=1,j=0;i<=q;i++){
    for(;j<(int)dat.size()&&dat[j].x>=Q[i].l;j++){
      upd(1,1,n,dat[j].y,n,get(dat[j]));
    }
    ans[Q[i].tid]=query(1,1,n,Q[i].r,Q[i].r);
  }
  rep(i,1,q)printf("%lld\n",ans[i]);
  return 0;
}