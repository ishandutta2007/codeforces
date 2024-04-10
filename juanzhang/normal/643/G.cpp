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
typedef pair<int,int> pii;
const int maxn=150010;
int n,q,P;

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

typedef vector<pii> vi;

int cov[maxn<<2];vi dat[maxn<<2];
//#define vp vi
//#define fi first
//#define se second
//vp merge( vp a , vp b ) {
////	for( auto t : a ) cout << t.fi << ' ' << t.se << endl;
////	puts("");
////	for( auto t : b ) cout << t.fi << ' ' << t.se << endl;
//	for( auto x : b ) {
//		int mn = 0x3f3f3f3f , ps = 0;
//		for( auto& t : a ) {
//			if( t.fi == x.fi ) { t.se += x.se , mn = -1; break; }
//			else
//				if( t.se < mn ) mn = t.se , ps = t.fi;
//		}
//		if( mn == -1 ) continue;
//		if( (int) a.size() < P ) a.push_back( x );
//		else if( x.se > mn ) {
//			for( auto& t : a ) if( t.fi == ps ) t = { x.fi , x.se - t.se }; else t.se -= mn;
//		} else for( auto& t : a ) t.se -= x.se;
//	}
//	return a;
//}
vi merge(vi A,vi B){
  for(const pii&t:B){
    bool flg=0;
    for(pii&p:A)if(p.first==t.first){
      p.second+=t.second,flg=1;break;
    }
    if(flg)continue;
    if((int)A.size()<P){
      A.push_back(t);continue;
    }
    int v=-1,mn=1e9;
    for(pii p:A)if(mn>p.second)v=p.first,mn=p.second;
    if(mn<t.second){
      for(pii&p:A){
        if(p.first==v)p=t;
        p.second-=mn;
      }
    }else for(pii&p:A)p.second-=t.second;
  }
  return A;
}
void pushtag(int k,int x,int l,int r){
  cov[k]=x,dat[k].clear(),dat[k].push_back({x,r-l+1});
}
void pushdown(int k,int l,int r){
  int&x=cov[k];
  if(x)pushtag(k<<1,x,l,mid),pushtag(k<<1|1,x,mid+1,r),x=0;
}
void build(int k,int l,int r){
  if(l==r){
    dat[k].push_back({read(),1});return;
  }
  build(lson),build(rson),dat[k]=merge(dat[k<<1],dat[k<<1|1]);
}
void upd(int k,int l,int r,int ql,int qr,int x){
  if(ql<=l&&r<=qr)return pushtag(k,x,l,r),void();
  pushdown(k,l,r);
  if(ql<=mid)upd(lson,ql,qr,x);
  if(qr>mid)upd(rson,ql,qr,x);
  dat[k]=merge(dat[k<<1],dat[k<<1|1]);
}
vi query(int k,int l,int r,int ql,int qr){
  if(ql<=l&&r<=qr)return dat[k];
  pushdown(k,l,r);
  if(qr<=mid)return query(lson,ql,qr);
  if(ql>mid)return query(rson,ql,qr);
  return merge(query(lson,ql,qr),query(rson,ql,qr));
}

#undef mid
#undef lson
#undef rson

void solve(){
  cin>>n>>q>>P,P=100/P;build(1,1,n);
  while(q--){
    int op=read(),l=read(),r=read();
    if(op==1){
      upd(1,1,n,l,r,read());
    }else{
      vi res=query(1,1,n,l,r);
      printf("%d ",(int)res.size());for(pii p:res)printf("%d ",p.first);puts("");
    }
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}