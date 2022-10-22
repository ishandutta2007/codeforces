#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=1e5+10;
int n,q,A[maxn],su[maxn];
struct line{
  int k,b;
  int get(int x){return k*x+b;}
}L[maxn];

vector<line>Q[maxn<<2];vector<double>cr[maxn<<2];
db cross(line l1,line l2){
  return(db)(l2.b-l1.b)/(l1.k-l2.k);
}
void build(int k,int l,int r){
  static int tid[maxn];
  rep(i,l,r)tid[i-l+1]=i;
  sort(tid+1,tid+r-l+1+1,[](int x,int y){
    return L[x].k>L[y].k||(L[x].k==L[y].k&&L[x].b<L[y].b);
  });
  int tot=0;
  rep(i,1,r-l+1)if(i==1||L[tid[i]].k!=L[tid[i-1]].k)tid[++tot]=tid[i];
  rep(id,1,tot){
    line l=L[tid[id]];
    while(!cr[k].empty()&&cr[k].back()>cross(Q[k].back(),l)){
      Q[k].pop_back(),cr[k].pop_back();
    }
    if(!Q[k].empty())cr[k].push_back(cross(Q[k].back(),l));
    Q[k].push_back(l);
  }int mid=(l+r)>>1;
  if(l!=r)build(k<<1,l,mid),build(k<<1|1,mid+1,r);
}
int query(int k,int l,int r,int ql,int qr,int x){
  if(ql<=l&&r<=qr){
    int ps=lower_bound(cr[k].begin(),cr[k].end(),x)-cr[k].begin();
    return Q[k][ps].get(x);
  }int mid=(l+r)>>1,res=INT_MAX;
  if(ql<=mid)res=query(k<<1,l,mid,ql,qr,x);
  if(qr>mid)chkmin(res,query(k<<1|1,mid+1,r,ql,qr,x));
  return res;
}

void solve(){
  cin>>n;
  rep(i,1,n)A[i]=read(),su[i]=su[i-1]+A[i],L[i]={A[i],i*A[i]-su[i]};
  build(1,1,n);
  cin>>q;
  while(q--){
    int x=read(),y=read();
    printf("%d\n",query(1,1,n,y-x+1,y,x-y)+su[y]);
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}