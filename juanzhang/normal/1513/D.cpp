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
const int maxn=2e5+10;
int n,k,A[maxn],st[maxn],lef[maxn],rig[maxn],par[maxn];pii dat[maxn];

int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}

void solve(){
  scanf("%d%d",&n,&k);
  rep(i,1,n)A[i]=read(),dat[i]={A[i],i},par[i]=i;
//  int top=0;st[0]=0;
//  rep(i,1,n){
//    while(top&&A[st[top]]>=A[i])top--;
//    lef[i]=st[top]+1,st[++top]=i;
//  }
//  top=0,st[0]=n+1;
//  per(i,n,1){
//    while(top&&A[st[top]]>=A[i])top--;
//    rig[i]=st[top]-1,st[++top]=i;
//  }
//  top=0,st[0]=0;
//  rep(i,1,n){
//    while(top&&A[st[top]]%A[i]==0)top--;
//    chkmax(lef[i],st[top]+1),st[++top]=i;
//  }
//  top=0,st[0]=n+1;
//  per(i,n,1){
//    while(top&&A[st[top]]%A[i]==0)top--;
//    chkmin(rig[i],st[top]-1),st[++top]=i;
//  }
////  rep(i,1,n)printf("(%d %d)\n",lef[i],rig[i]);
  ll ans=0;
//  set<int>seq;
//  rep(i,1,n)par[i]=i,seq.insert(i);
  sort(dat+1,dat+n+1);
  rep(i,1,n){
    int l=i,r=i;
    while(l>1&&A[l-1]%A[i]==0){
      if(A[--l]==A[i])break;
    }
    while(r<n&&A[r+1]%A[i]==0){
      if(A[++r]==A[i])break;
    }
    lef[i]=l,rig[i]=r;
  }
  int ct=0;
  rep(_,1,n)if(dat[_].first<k){
    int p=dat[_].second;
    rep(i,lef[p]+1,rig[p])if(find(i)!=find(i-1)){
      par[find(i)]=find(i-1),ct++,ans+=dat[_].first;
    }
  }
  ans+=1ll*k*(n-ct-1);
//  rep(_,1,n){
//    int x=dat[_].first,p=dat[_].second;
//    if(x>=k)break;
//    int l=lef[p],r=rig[p];
//    set<int>S;
//    auto it=seq.lower_bound(l);
//    while(it!=seq.end()&&*it<=r){
//      S.insert(*it++);
//    }
//    if(S.empty())continue;
//    ans+=1ll*x*((int)S.size()-1);
////    printf("#%lld\n",ans);
//    int lst=-1;
//    for(int u:S){
//      if(lst==-1)lst=u;
//      else par[u]=lst;
//    }
//    seq.erase(seq.lower_bound(l),seq.upper_bound(r));
//    seq.insert(lst);
//  }
//  ans+=1ll*k*((int)seq.size()-1);
  printf("%lld\n",ans);
  rep(i,0,n+1)A[i]=st[i]=lef[i]=rig[i]=0;
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}