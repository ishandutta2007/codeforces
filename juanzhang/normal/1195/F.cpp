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
int n,q,pos[maxn];

int abso(int x){return x<0?-x:x;}
struct point{
  int x,y;
}dat[maxn*3];
struct frac{
  int P,Q;
  void zzh(){
    int g=abso(__gcd(P,Q));P/=g,Q/=g;
  }
  ll get(){return P*1000000001ll+Q;}
};
map<ll,int>mp;
ll val[maxn*3];int lst[maxn*3];

int tot,rt[maxn],ls[maxn*60],rs[maxn*60],sum[maxn*60];
void ins(int&k,int rt,int l,int r,int x){
  sum[k=++tot]=sum[rt]+1,ls[k]=ls[rt],rs[k]=rs[rt];
  if(l==r)return;int mid=(l+r)/2;
  x<=mid?ins(ls[k],ls[rt],l,mid,x):ins(rs[k],rs[rt],mid+1,r,x);
}
int query(int k,int l,int r,int x){
  if(r<=x)return sum[k];int mid=(l+r)>>1;
  return x<=mid?query(ls[k],l,mid,x):sum[ls[k]]+query(rs[k],mid+1,r,x);
}

void solve(){
  cin>>n;
  rep(i,1,n){
    int k=read();
    pos[i]=pos[i-1]+k,rt[i]=rt[i-1];
    rep(j,1,k){
      dat[j].x=read(),dat[j].y=read();
    }
    rep(j,1,k){
      frac tp={dat[j%k+1].y-dat[j].y,dat[j%k+1].x-dat[j].x};
      tp.zzh();
      int x=pos[i-1]+j;ll v=tp.get();
      val[x]=v,lst[x]=mp[v],mp[v]=i;
      ins(rt[i],rt[i],0,n-1,lst[x]);
//      printf("#%d %d (%d)\n",tp.P,tp.Q,lst[x]);
    }
  }
  cin>>q;
  while(q--){
    int l=read(),r=read();
    printf("%d\n",query(rt[r],0,n-1,l-1)-pos[l-1]);
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}