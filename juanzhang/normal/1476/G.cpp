#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  bool f=0;int x=0;char c=nc;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

const int maxn=1e5+10;
int n,q,ut,A[maxn];

struct Upds{
  int p,x,lst;
}U[maxn];
struct Querys{
  int l,r,k,t,id;
}Q[maxn];int bsz,bl[maxn],ans[maxn];

int L,R,T;
int occ[maxn];
int beg,pre[maxn],nxt[maxn],cnt[maxn];

void add(int x){
  int&t=occ[x];
  cnt[t+1]++;
  if(t){
    if(nxt[t]!=t+1){
      nxt[t+1]=nxt[t],pre[t+1]=t;
      if(t)pre[nxt[t]]=t+1,nxt[t]=t+1;
    }
    if(!--cnt[t]){
      if(beg==t)beg=nxt[t],pre[beg]=nxt[t]=0;
      else pre[nxt[t]]=pre[t],nxt[pre[t]]=nxt[t],pre[t]=nxt[t]=0;
    }
  }else{
    if(beg>1)pre[beg]=1,nxt[1]=beg;
    beg=1;
  }
  t++;
}
void del(int x){
  int&t=occ[x];
  if(t>1){
    cnt[t-1]++;
    if(pre[t]!=t-1){
      if(beg==t)beg=t-1;
      pre[t-1]=pre[t],nxt[t-1]=t;
      nxt[pre[t]]=t-1,pre[t]=t-1;
    }
  }
  if(!--cnt[t]){
    if(beg==t)beg=nxt[t];
    if(nxt[t])pre[nxt[t]]=pre[t];
    nxt[pre[t]]=nxt[t];
    pre[t]=nxt[t]=0;
  }
  t--;
}

int main(){
  int tpq;cin>>n>>tpq;bsz=max(1,(int)pow(n,0.7));
  rep(i,1,n)A[i]=read();
  rep(i,1,tpq){
    int op=read();bl[i]=(i-1)/bsz+1;
    if(op==1)Q[++q].l=read(),Q[q].r=read(),Q[q].k=read(),Q[q].id=q,Q[q].t=ut;
    else U[++ut].p=read(),U[ut].lst=A[U[ut].p],A[U[ut].p]=U[ut].x=read();
  }
  sort(Q+1,Q+q+1,[](Querys A,Querys B){
    return bl[A.l]!=bl[B.l]?A.l<B.l:bl[A.r]!=bl[B.r]?A.r<B.r:A.id<B.id;
  });
  L=1,R=0,T=ut;
  rep(i,1,q){
    while(T<Q[i].t){
      int pos=U[++T].p;
      if(L<=pos&&pos<=R){
        del(A[pos]),add(U[T].x);
      }
      A[pos]=U[T].x;
    }
    while(T>Q[i].t){
      int pos=U[T].p;
      if(L<=pos&&pos<=R){
        del(A[pos]),add(U[T].lst);
      }
      A[pos]=U[T--].lst;
    }
//    for(int u=beg;u;u=nxt[u])printf("(%d %d) ",u,cnt[u]);puts("");
    while(L>Q[i].l)add(A[--L]);
    while(R<Q[i].r)add(A[++R]);
    while(L<Q[i].l)del(A[L++]);
    while(R>Q[i].r)del(A[R--]);
//    printf("#(%d %d %d)\n",L,R,T);
//    for(int u=beg;u;u=nxt[u])printf("(%d %d) ",u,cnt[u]);puts("");
    int res=1e9;
    for(int p=beg,q=beg,ct=0;p;p=nxt[p]){
      ct+=cnt[p];
      while(p!=q&&ct-cnt[q]>=Q[i].k)ct-=cnt[q],q=nxt[q];
      if(ct>=Q[i].k)chkmin(res,p-q);
    }
    ans[Q[i].id]=res>1e8?-1:res;
  }
  rep(i,1,q)printf("%d\n",ans[i]);
  return 0;
}