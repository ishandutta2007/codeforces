#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  bool f=0;int x=0;char c=nc;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
int n;
char str[5050];
char dx[114],dy[114];

set<pii>vis;

bool check(int px,int py){
//  printf("(%d %d)\n",px,py);
  int x=0,y=0;
  rep(i,1,n){
    int nx=x+dx[str[i]],ny=y+dy[str[i]];
    if(nx!=px||ny!=py)x=nx,y=ny;
  }
  return !x&&!y;
}

void solve(){
  vis.clear();
  scanf("%s",str+1),n=strlen(str+1);
  int x=0,y=0;
  vis.insert({0,0});
  rep(i,1,n){
    int nx=x+dx[str[i]],ny=y+dy[str[i]];
    if(vis.insert({nx,ny}).second){
      if(check(nx,ny)){
        printf("%d %d\n",nx,ny);return;
      }
    }
    x=nx,y=ny;
  }
  if(check(114514,114514)){
    puts("114514 114514");
  }else
  puts("0 0");
}

signed main(){
  dx['L']=-1,dx['R']=1,dy['D']=-1,dy['U']=1;
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}