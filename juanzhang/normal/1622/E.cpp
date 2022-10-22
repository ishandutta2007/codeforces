#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

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
  static char st[11];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

const int maxn=1e4+10;
int n,m,goal[10];
char str[10][maxn];

int ans,tmp[maxn];

vector<int>buk[30];

int coef[maxn];

void solve(){
  scanf("%d%d",&n,&m);
  rep(i,0,n-1)scanf("%d",goal+i);
  rep(i,0,n-1){
    scanf("%s",str[i]+1);
  }
  ans=-1;
  rep(S,0,(1<<n)-1){
    memset(coef,0,(m+1)<<2);
    int res=0;
    rep(i,0,n-1){
      res+=goal[i]*(S>>i&1?1:-1);
      rep(j,1,m)if(str[i][j]=='1'){
        coef[j]+=S>>i&1?-1:1;
      }
    }
    rep(i,1,m){
      buk[coef[i]+15].push_back(i);
    }
    static int A[maxn];
    int cur=m;
    per(i,29,0){
      for(int j:buk[i]){
        A[j]=cur;
        res+=(i-15)*cur;
        cur--;
      }
      buk[i].clear();
    }
    if(ans<res){
      ans=res;
      memcpy(tmp,A,(m+1)<<2);
    }
  }
  rep(i,1,m)printf("%d%c",tmp[i],"\n "[i<m]);
}

signed main(){
  int T;cin>>T;
  while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}