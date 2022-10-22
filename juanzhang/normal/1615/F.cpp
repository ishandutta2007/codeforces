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

const int P=1e9+7;
int n;
char S[2010],T[2010];
int pre_S[2010][2],pre_T[2010][2];

int C[4010][4010];

namespace Arraiter{
  
int calc(int n,int m,int dt){
  if(dt<0)dt=-dt,swap(n,m);
  int res=0;
  res=n>=dt?C[n+m][n-dt]:0;
//  rep(j,0,min(m,n-dt)){
//    res=(res+1ll*C[n][j+dt]*C[m][j])%P;
//  }
//  rep(i,0,n)rep(j,0,m)if(i-j==dt){
//    res=(res+1ll*C[n][i]*C[m][j])%P;
//  }
  return res;
}

void solve(){
  scanf("%d%s%s",&n,S+1,T+1);
  rep(i,1,n)if(i%2==0){
    if(S[i]!='?')S[i]^=1;
    if(T[i]!='?')T[i]^=1;
  }
  rep(i,1,n)rep(j,0,1)pre_S[i][j]=pre_S[i-1][j]+(S[i]==48+j);
  rep(i,1,n)rep(j,0,1)pre_T[i][j]=pre_T[i-1][j]+(T[i]==48+j);
  int ans=0;
  rep(i,1,n)rep(j,1,n)if(S[i]!='0'&&T[j]!='0'){
    int res=0;
    {
      int x1=pre_S[i-1][1],y1=i-1-x1-pre_S[i-1][0];
      int x2=pre_T[j-1][1],y2=j-1-x2-pre_T[j-1][0];
      res=calc(y1,y2,x2-x1);
    }
    {
      int x1=pre_S[n][1]-pre_S[i][1],y1=n-i-x1-(pre_S[n][0]-pre_S[i][0]);
      int x2=pre_T[n][1]-pre_T[j][1],y2=n-j-x2-(pre_T[n][0]-pre_T[j][0]);
      res=1ll*res*calc(y1,y2,x2-x1)%P;
    }
    ans=(ans+1ll*abs(i-j)*res)%P;
  }
  write(ans),pc(10);
}

}

signed main(){
  rep(i,0,4000){
    C[i][0]=1;
    rep(j,1,i)C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
  }
  int T=read();
  while(T--)Arraiter::solve();
//  solve();
  orzjk::flush();
  return 0;
}