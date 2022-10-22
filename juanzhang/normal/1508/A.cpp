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
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=5e5+10;
int n,A[maxn],B[maxn],C[maxn];

void get(int*A){
  static char str[maxn];
  scanf("%s",str+1);rep(i,1,n)A[i]=str[i]-'0';
}
//bool run(int*A,int*B){
////  A[n+1]=B[n+1]=-1;
////  rep(i,0,n+1)dp[i]=rig[i]=0;
////  per(i,n,1)rig[i]=B[i]==B[i+1]?rig[i+1]:i;
//  int i=0,j=0;string ans="";
//  while(i<n||j<n){
//    if(i==n){
//      ans+=B[++j]+'0';
//    }else if(j==n){
//      ans+=A[++i]+'0';
//    }else if(A[i+1]==B[j+1]){
//      ans+=A[++i]+'0',j++;
//    }else{
//      if(i<=j){
//        ans+=A[++i]+'0';
//      }else{
//        ans+=B[++j]+'0';
//      }
//    }
//  }
//  if((int)ans.size()<=n/2*3){
//    for(char c:ans)putchar(c);puts("");
//    return 1;
//  }
//  return 0;
//}

void solve(){
  cin>>n,n*=2,get(A),get(B),get(C);
  int i=0,j=0,k=0;string ans="";
  while((i<n)+(j<n)+(k<n)==3){
    int ct0=(!A[i+1])+(!B[j+1])+(!C[k+1]);
    int ct1=(A[i+1])+(B[j+1])+(C[k+1]);
    int x=ct0>ct1?0:1;
    ans+=x+'0';
    i+=A[i+1]==x;
    j+=B[j+1]==x;
    k+=C[k+1]==x;
  }
  if(i==n){
    if(j<k){
      while(k<n)ans+=C[++k]+'0';
    }else{
      while(j<n)ans+=B[++j]+'0';
    }
  }else if(j==n){
    if(i<k){
      while(k<n)ans+=C[++k]+'0';
    }else{
      while(i<n)ans+=A[++i]+'0';
    }
  }else{
    if(i<j){
      while(j<n)ans+=B[++j]+'0';
    }else{
      while(i<n)ans+=A[++i]+'0';
    }
  }
  for(char c:ans)putchar(c);puts("");
//  if(run(A,B))return;
//  if(run(B,C))return;
//  if(run(A,C))return;
//  assert(0);
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}