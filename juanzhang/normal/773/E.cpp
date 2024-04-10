#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef pair<int,int>pii;
const int maxn=5e5+10;
int n,pos[maxn];pii A[maxn];

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

int tag[maxn<<2],val[maxn<<2],sz[maxn<<2],vmn[maxn<<2];
void pushtag(int k,int x){
  tag[k]+=x,val[k]+=x,vmn[k]-=x;
}
void pushdown(int k){
  int&x=tag[k];if(x)pushtag(k<<1,x),pushtag(k<<1|1,x),x=0;
}
void maintain(int k){
  sz[k]=sz[k<<1]+sz[k<<1|1],val[k]=max(val[k<<1],val[k<<1|1]),vmn[k]=min(vmn[k<<1],vmn[k<<1|1]);
}
int query_sz(int k,int l,int r,int x){
  if(r<=x)return sz[k];
  pushdown(k);
  return x<=mid?query_sz(lson,x):sz[k<<1]+query_sz(rson,x);
}
void ins(int k,int l,int r,int x,int v1,int v2){
  if(l==r)return val[k]=v1,vmn[k]=v2,sz[k]=1,void();
  pushdown(k);
  x<=mid?ins(lson,x,v1,v2):ins(rson,x,v1,v2),maintain(k);
}
void add(int k,int l,int r,int x){
  if(x<=l){
    pushtag(k,1);return;
  }
  pushdown(k);
  if(x<=mid)add(lson,x);
  add(rson,x);
  maintain(k);
}
int query_pos(int k,int l,int r){
  if(l==r){
    if(val[k]<0)return -1;
    return l;
  }
  pushdown(k);
  if(val[k<<1]>=0){
    return query_pos(lson);
  }else{
    return query_pos(rson);
  }
}
int query_min(int k,int l,int r,int x){
  if(x<=l)return vmn[k];
  pushdown(k);
  return x<=mid?min(vmn[k<<1|1],query_min(lson,x)):query_min(rson,x);
}

#undef mid
#undef lson
#undef rson

int main(){
  cin>>n;
  rep(i,1,n){
    int x;scanf("%d",&x),A[i]={x,i};
  }
  sort(A+1,A+n+1);
  rep(i,1,n)pos[A[i].second]=i;
  memset(vmn,0x3f,sizeof vmn);
  memset(val,-0x3f,sizeof val);
  rep(_,1,n){
    int p=pos[_],x=A[p].first;
    int rk=query_sz(1,1,n,p)+1;
//    printf("#%d %d\n",p,rk);
    ins(1,1,n,p,x+rk,x-rk);
    if(p<n)add(1,1,n,p+1);
    int pos=query_pos(1,1,n);
    if(pos==-1){
      printf("%d\n",-_);continue;
    }
//    printf("!!%d\n",query_sz(1,1,n,pos));
    int res=-2*(query_sz(1,1,n,pos)-1);
    res=min(res,query_min(1,1,n,pos));
    printf("%d\n",_+res);
  }
  return 0;
}