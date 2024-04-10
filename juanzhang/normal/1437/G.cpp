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
const int maxn=3e5+10;
int n,q,pos[maxn],A[maxn];
char str[maxn];

vi E[maxn];
int sz[maxn],tid[maxn];
void dfs(int u){
  static int now;
  tid[u]=now++,sz[u]=1;
  for(int v:E[u]){
    dfs(v),sz[u]+=sz[v];
  }
}

int tot,ch[maxn][26],fail[maxn],Q[maxn];

void ins(int p){
  int len=strlen(str+1),cur=0;
  rep(i,1,len){
    int&x=ch[cur][str[i]-'a'];
    cur=x?x:x=++tot;
  }
  pos[p]=cur;
}

void build(){
  int l=1,r=0;
  rep(i,0,25)if(ch[0][i]){
    Q[++r]=ch[0][i];
  }
  while(l<=r){
    int u=Q[l++];
    rep(i,0,25){
      int&v=ch[u][i],k=ch[fail[u]][i];
      if(v){
        fail[v]=k,Q[++r]=v;
      }else{
        v=k;
      }
    }
  }
  rep(i,1,tot){
    E[fail[i]].push_back(i);
  }
}

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

multiset<int>val[maxn<<2];

void upd(int k,int l,int r,int ql,int qr,int x,int v){
  if(ql<=l&&r<=qr){
    if(v==1)val[k].insert(x);
    else val[k].erase(val[k].find(x));
    return;
  }
  if(ql<=mid)upd(lson,ql,qr,x,v);
  if(qr>mid)upd(rson,ql,qr,x,v);
}

int query(int k,int l,int r,int x){
  int res=val[k].empty()?-1:*val[k].rbegin();
  if(l==r)return res;
  return max(res,x<=mid?query(lson,x):query(rson,x));
}

#undef mid
#undef lson
#undef rson

void solve() {
  cin>>n>>q;
  rep(i,1,n){
    scanf("%s",str+1),ins(i);
  }
  build(),dfs(0);
  rep(i,1,n)upd(1,0,tot,tid[pos[i]],tid[pos[i]]+sz[pos[i]]-1,0,1),A[i]=0;
  while(q--){
    int op=read();
    if(op==1){
      int i=read(),x=read(),u=pos[i];
      upd(1,0,tot,tid[u],tid[u]+sz[u]-1,A[i],-1);
      upd(1,0,tot,tid[u],tid[u]+sz[u]-1,A[i]=x,1);
    }else{
      scanf("%s",str+1);
      int len=strlen(str+1),cur=0,res=-1;
      rep(i,1,len){
        cur=ch[cur][str[i]-'a'];
        chkmax(res,query(1,0,tot,tid[cur]));
      }
      printf("%d\n",res);
    }
  }
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}