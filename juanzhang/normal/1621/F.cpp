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

const int maxn=1e5+10;

int n,a,b,c;
char S[maxn];int A[maxn];

ll calc(vi vec,int ct0,int ct1,int tmp0,int lst){
//  printf("(0 : %d) (1 : %d)\n",ct0,ct1);
//  for(int x:vec)printf("!%d\n",x);
  ll ans=0;
  if(!lst){
    if(!ct1)return 0;
    ct1--,ans+=b,lst=1;
  }
  for(int sz:vec){
    bool flg=0;
    if(sz>n){
      sz-=n+1;
      flg=1;
    }
    while(sz>1){
      sz--;
      lst=0;
      ans+=a;
      if(!ct1)break;
      ct1--;
      ans+=b;
      lst=1;
    }
    if(lst==0)break;
    if(c<b&&!flg){
      ans-=c;
      lst=0;
      ans+=b;
      lst=1;
    }else{
      tmp0++;
    }
  }
//  printf("$%d %lld %d\n",tmp0,ans,ct1);
  if(c<b){
    if(lst!=0)while(tmp0&&ct1){
      ans+=b-c;
      tmp0--,ct1--;
    }
  }
  return ans;
}

void solve(){
  scanf("%d%d%d%d%s",&n,&a,&b,&c,S+1);
  rep(i,1,n)A[i]=S[i]-48;
  int ct1=0,ct0=0,tmp0=0;
  vi vec;
  rep(i,1,n){
    int j=i;
    while(j<n&&A[j+1]==A[i])j++;
    if(A[i]==1){
      ct1+=j-i;
    }else{
      if(i==1||j==n){
        vec.push_back(n+1+(j-i+1));
//        tmp0++;
      }else{
        vec.push_back(j-i+1);
      }
    }
    i=j;
  }
  sort(vec.begin(),vec.end());
  ll ans=0;
  ans=calc(vec,ct0,ct1,tmp0,1); // op 1
  ll tmp=calc(vec,ct0,ct1,tmp0,0);
  chkmax(ans,tmp);
  cout<<ans<<endl;
}

signed main(){
  int T;cin>>T;
  while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}