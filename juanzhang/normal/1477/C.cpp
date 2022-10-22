#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=5050;
int n;
struct point{
  int x,y;
}A[maxn];
bool vis[maxn];
ll sqr(int x){
  return 1ll*x*x;
}
ll get(int i,int j){
  return sqr(A[i].x-A[j].x)+sqr(A[i].y-A[j].y);
}

signed main(){
  cin>>n;int st=1;
  rep(i,1,n){
    cin>>A[i].x>>A[i].y;
    if(A[i].x<A[st].x)st=i;
  }
  vis[st]=1;printf("%d ",st);
  rep(T,1,n-1){
    int mn=-1;ll tp=0;
    rep(i,1,n)if(!vis[i]&&get(st,i)>tp)mn=i,tp=get(st,i);
    printf("%d ",mn),vis[mn]=1,st=mn;
  }
  return 0;
}