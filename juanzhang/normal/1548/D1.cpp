#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define mem(x) memset((x),0,sizeof(x))

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

typedef unsigned u32;
typedef unsigned uint;
typedef unsigned long long u64;

namespace orzjk{
  const int SZ=1e6;
  char buf[SZ],*p1=buf,*p2=buf;
  char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
  }
  char fub[SZ],*p3=fub,*p4=fub+SZ;
  void pc(char c){
    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
    *p3++=c;
  }
  void flush(){
    fwrite(fub,1,p3-fub,stdout),p3=fub;
  }
}
using orzjk::nc;
using orzjk::pc;

//#define nc getchar
//#define pc putchar

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(int x){
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

//const int P=1e9+7;
const int P=998244353;
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

int n;

struct point{
  int x,y;
  int get(){
    return __gcd(x,y);
  }
}A[6010];
point operator-(point A,point B){
  return{A.x-B.x,A.y-B.y};
}

int val[6010];

void solve(){
  n=read();
  rep(i,1,n){
    A[i].x=read()/2,A[i].y=read()/2;
  }
  ll ans=0;
  rep(S,1,n){
    int ct[2][2][2],all[2]={0,0};
    memset(ct,0,sizeof ct);
    rep(i,S+1,n){
      val[i]=(A[S]-A[i]).get()&1;
      ans+=val[i]?all[0]-ct[A[i].x&1][A[i].y&1][0]:ct[A[i].x&1][A[i].y&1][0];
      ans+=val[i]?ct[A[i].x&1][A[i].y&1][1]:all[1]-ct[A[i].x&1][A[i].y&1][1];
      ct[A[i].x&1][A[i].y&1][val[i]]++,all[val[i]]++;
    }
//    rep(i,S+1,n)rep(j,i+1,n){
//      int x=(A[i].x&1)==(A[j].x&1)&&(A[i].y&1)==(A[j].y&1);
//      ans+=(val[i]+val[j]+(!x))%2==0;
////      ans+=(val[i]+val[j]+((A[i]-A[j]).get()&1))%2==0;
//    }
  }
  cout<<ans<<endl;
}

signed main(){
//  int T;cin>>T;while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}