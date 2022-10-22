#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

#define int long long

typedef pair<int,int>pii;
const int maxn=2e5+10;
int n,k,kk,A[maxn];

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

int tag[maxn<<2],val[maxn<<2];
void pushtag(int k,int x){
  tag[k]+=x,val[k]+=x;
}
void pushdown(int k){
  int&x=tag[k];
  if(x){
    pushtag(k<<1,x);
    pushtag(k<<1|1,x);
    x=0;
  }
}
void maintain(int k){
  val[k]=min(val[k<<1],val[k<<1|1]);
}
void build(int k,int l,int r){
  tag[k]=0;
  if(l==r)val[k]=l;
  else build(lson),build(rson),maintain(k);
}
void add(int k,int l,int r,int ql,int qr,int x){
  if(ql<=l&&r<=qr)return pushtag(k,x);
  pushdown(k);
  if(ql<=mid)add(lson,ql,qr,x);
  if(qr>mid)add(rson,ql,qr,x);
  maintain(k);
}
void add(int l,int r,int x){
  add(1,1,n,l,r,x);
}
int my_find(int k,int l,int r){
  if(l==r)return l;
  pushdown(k);
  if(val[k<<1]<=kk){
    return my_find(lson);
  }else{
    return my_find(rson);
  }
}

#undef mid
#undef lson
#undef rson

int top_min,st_min[maxn];
int top_max,st_max[maxn];

pii solve(){
  kk=k;
  build(1,1,n);
  map<int,int>lst;
  top_min=0;
  top_max=0;
  rep(i,0,n+1)st_min[i]=st_max[i]=0;
  int cur=1;
  pii ans(1,1);
  rep(i,1,n){
    while(top_max&&A[st_max[top_max]]<=A[i])add(st_max[top_max-1]+1,st_max[top_max],-A[st_max[top_max]]),top_max--;
    add(st_max[top_max]+1,i, A[i]),st_max[++top_max]=i;
    while(top_min&&A[st_min[top_min]]>=A[i])add(st_min[top_min-1]+1,st_min[top_min], A[st_min[top_min]]),top_min--;
    add(st_min[top_min]+1,i,-A[i]),st_min[++top_min]=i;
    add(1,n,-1);
    int tmp=lst[A[i]];
    while(cur<=tmp){
      add(cur,cur,1e18);
      cur++;
    }
    lst[A[i]]=i;
    // first leq k
    int pos=my_find(1,1,n);
    if(i-pos>ans.second-ans.first)ans=pii(pos,i);
  }
  return ans;
}

signed main(){
  ios::sync_with_stdio(0);
  int n,d;
  static int A[maxn];
  cin>>n>>k>>d;
  rep(i,1,n)cin>>A[i],A[i]+=1000000000;
  pii ans(1,1);
  if(!d){
    rep(i,1,n){
      int j=i;
      while(j<n&&A[j+1]==A[i])j++;
      if(j-i>ans.second-ans.first)ans=pii(i,j);
      i=j;
    }
    cout<<ans.first<<' '<<ans.second<<endl;
    return 0;
  }
  rep(i,1,n){
    int j=i;
    while(j<n&&A[j+1]%d==A[i]%d)j++;
    ::n=j-i+1;
    rep(k,1,::n)::A[k]=A[i+k-1]/d;
    pii p=solve();
    p.first+=i-1;
    p.second+=i-1;
    if(p.second-p.first>ans.second-ans.first)ans=p;
    i=j;
  }
  cout<<ans.first<<' '<<ans.second<<endl;
  return 0;
}