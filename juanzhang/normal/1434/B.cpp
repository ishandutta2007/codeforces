#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read() {
  #define nc getchar()
  int x=0;char c=nc;
  while(c<48)c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=2e5+10;
int n;
struct node{
  int op,x;
}Q[maxn];

set<int>S;
bool vis[maxn];
int top,st[maxn],pos[maxn],ans[maxn];

void solve() {
  cin>>n;
  int now=n,cur=0;
  rep(T,1,n+n){
    char ch;
    scanf("%s",&ch);
    while(!S.empty()&&vis[*S.rbegin()])S.erase(*S.rbegin());
    if(ch=='+'){
      Q[T].op=1;
      while(vis[now]&&now>0){
        now--;
      }
      int x=now;
      if((!x||vis[x])||(!S.empty()&&*S.rbegin()>x)){
        x=*S.rbegin();
        S.erase(x);
      }
      st[++top]=x,vis[x]=1,pos[top]=++cur,ans[cur]=x;
    }else{
      int x=read();
      Q[T].x=x;
      if(!top||st[top]<x)return puts("NO"),void();
      if(st[top]>x){
        vis[st[top]]=0,S.insert(st[top]);
      }
      vis[x]=1,ans[pos[top]]=x;
      top--;
    }
  }
  if(cur<n||!S.empty())return puts("NO"),void();
  cur=0;
  rep(T,1,2*n){
    if(Q[T].op==1){
      S.insert(ans[++cur]);
    }else{
      int x=*S.begin();
      if(x!=Q[T].x)return puts("NO"),void();
      S.erase(x);
    }
  }
  puts("YES");
  rep(i,1,n)printf("%d ",ans[i]);
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}