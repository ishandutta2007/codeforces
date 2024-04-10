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
int N,p[114];

ll qp(ll x,int y){
  ll res=1;
  while(y--){
    if((long double)res*x>1e18)return -1;
    res*=x;
  }
  return res;
}

ll getv(ll x){
  ll res=0;
  per(i,N-1,0){
    if((long double)res*x+p[i]>1e18)return -1;
    res=res*x+p[i];
  }
  return res;
}

void solve(){
  ll t,a,b;
  cin>>t>>a>>b;int res=a==b?1:0,tt=-1,ct=0;
  if(t>a||a>b||(t==a&&a==1&&b>1))return printf("%d\n",res),void();
  if(b==1)return puts("inf"),void();
  if(a!=1){
    for(ll tp=b;tp;tp/=a)p[N++]=tp%a,ct+=tp%a!=0;
    res+=getv(t)==a&&getv(a)==b;
    if(ct==1)tt=N-1;
  }
  ll zzh=1,yyh=1;
  rep(i,1,60){
    if((long double)yyh*a>1e18)break;
    zzh*=t,yyh*=a;
    if(i!=tt&&a%zzh==0&&b%yyh==0&&a/zzh==b/yyh)res++;
  }
  cout<<res<<endl;
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}