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

//namespace orzjk{
//  const int SZ=1e6;
//  char buf[SZ],*p1=buf,*p2=buf;
//  char nc(){
//    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
//  }
//  char fub[SZ],*p3=fub,*p4=fub+SZ;
//  void pc(char c){
//    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
//    *p3++=c;
//  }
//  void flush(){
//    fwrite(fub,1,p3-fub,stdout),p3=fub;
//  }
//}
//using orzjk::nc;
//using orzjk::pc;

#define nc getchar
#define pc putchar

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
template<class T>void write(T x){
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

const int maxn=1e5+10;

void solve(){
  int n;
  vi tid;
  cin>>n;
  rep(i,1,n)tid.pb(i);
  rep(_,1,41){
    if(n<=2)break;
    vi A[2],B[2];
    rep(i,1,n/2)A[0].pb(tid[i-1]);
    rep(i,n/2+1,n)A[1].pb(tid[i-1]);
    rep(i,0,n-1)B[i&1].pb(tid[i]);
    cout<<"? ";
    cout<<A[0].size()<<' ';
    for(int x:A[0])cout<<x<<' ';
    cout<<endl;
    fflush(stdout);
    string str0,str1;
    cin>>str0;
    cout<<"? ";
    cout<<B[0].size()<<" ";
    for(int x:B[0])cout<<x<<' ';
    cout<<endl;
    fflush(stdout);
    cin>>str1;
    bool f0=str0=="YES";
    bool f1=str1=="YES";
    vi nxt;
    static int vis[maxn],tim;
    ++tim;
    for(int x:A[!f0])nxt.pb(x),vis[x]=tim;
    for(int x:B[!f1])if(vis[x]!=tim)nxt.pb(x);
    tid.swap(nxt);
    n=tid.size();
  }
  while(!tid.empty()){
    int x=tid.back();
    cout<<"! "<<x<<endl;
    fflush(stdout);
    string str;
    cin>>str;
    if(str==":)")return;
    tid.pop_back();
  }
}

signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
//  int T;cin>>T;while(T--)solve();
  solve();
//  orzjk::flush();
  return 0;
}