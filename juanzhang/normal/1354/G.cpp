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
int n,k,pos;char str[10];

void find(int l,int r){
  if(l==r)return pos=l,void();
  int mid=(l+r)/2;
  printf("? %d %d\n",mid-l+1,r-mid);
  rep(i,l,mid)printf("%d ",i);puts("");
  rep(i,mid+1,r)printf("%d ",i);puts("");
  fflush(stdout);
  scanf("%s",str);
  *str=='S'?find(mid+1,r):find(l,mid);
}

void solve() {
  srand(time(0));
  cin>>n>>k;
  rep(T,1,30){
    int x=rand()%(n-1)+2;
    printf("? 1 1\n1\n%d\n",x),fflush(stdout),scanf("%s",str);
    if(*str=='S')return puts("! 1"),fflush(stdout),void();
  }
//  int len=1;
//  while(len*2<=n)len<<=1;
//  find(1,len);
//  if(pos!=1){
//    printf("? %d %d\n%d\n%d\n",1,1,1,pos);
//    fflush(stdout),scanf("%s",str);
//    if(*str=='S'){
//      printf("! %d\n",1),fflush(stdout);return;
//    }
//  }
  int cur=1;
  for(;(1<<cur)<=n;cur++){
    int mid=1<<(cur-1);
    printf("? %d %d\n",mid,mid);
    rep(i,1,mid)printf("%d ",i);puts("");
    rep(i,1,mid)printf("%d ",mid+i);puts("");
    fflush(stdout),scanf("%s",str);
    if(*str=='F')break;
  }
  int pos=(1<<(cur-1));
  per(i,cur-2,0)if(pos+(1<<i)<n){
    printf("? %d %d\n",1<<i,1<<i);
    rep(j,1,1<<i)printf("%d ",j);puts("");
    rep(j,1,1<<i)printf("%d ",pos+j);puts("");
    fflush(stdout),scanf("%s",str);
    if(*str=='E'){
      pos+=1<<i;
    }
  }
  printf("! %d\n",pos+1),fflush(stdout);
}

signed main() {
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}