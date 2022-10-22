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
const int maxn=1e5+10;
int n,m,q,par[maxn];vi E[maxn];
int find(int x){return par[x]==x?x:par[x]=find(par[x]);}

map<pii,ll>ans;
int bsz,mxv[maxn],val[maxn];pii dat[maxn];
vi nod[maxn],vec[maxn];vector<ll>su[maxn];

int dis[maxn];
void dfs(int u,int f){
  for(int v:E[u])if(v!=f)dis[v]=dis[u]+1,dfs(v,u);
}

void solve(){
  cin>>n>>m>>q;
  bsz=sqrt(n);
  rep(i,1,n)par[i]=i;
  rep(i,1,m){
    int u=read(),v=read();par[find(u)]=find(v),E[u].push_back(v),E[v].push_back(u);
  }
  rep(i,1,n)nod[find(i)].push_back(i);
  rep(i,1,n)if(find(i)==i){
    int S=i,T=i;
    dis[i]=0,dfs(i,0);
    for(int x:nod[i])if(dis[x]>dis[S])S=x;
    dis[S]=0,dfs(S,0);
    for(int x:nod[i]){
      chkmax(val[x],dis[x]);
      if(dis[x]>dis[T])T=x;
    }
    mxv[i]=dis[T];
    dis[T]=0,dfs(T,0);
    for(int x:nod[i])chkmax(val[x],dis[x]);
  }
  rep(i,1,n)vec[find(i)].push_back(val[i]);
  rep(i,1,n){
    dat[i]={val[i],i};
    sort(vec[i].begin(),vec[i].end());ll tp=0;
    for(int x:vec[i])su[i].push_back(tp+=x);
  }
  sort(dat+1,dat+n+1);
  rep(i,1,n)if((int)nod[i].size()>bsz){
    static int ct1[maxn],ct2[maxn];static ll sum[maxn],tmp[maxn];
    memset(ct1,0,(n+1)<<2),memset(ct2,0,(n+1)<<2);
    memset(sum,0,(n+1)<<3),memset(tmp,0,(n+1)<<3);
    for(int x:nod[i]){
      int ps=upper_bound(dat+1,dat+n+1,pii(mxv[i]-val[x]-1,n+1))-dat;
      ct1[1]++,ct1[ps]--,ct2[ps]++,sum[ps]+=val[x]+1;
    }
    rep(j,1,n){
      ct1[j]+=ct1[j-1],ct2[j]+=ct2[j-1],sum[j]+=sum[j-1];
      tmp[find(dat[j].second)]+=1ll*ct1[j]*mxv[i]+1ll*ct2[j]*val[dat[j].second]+sum[j];
    }
    rep(k,1,n)if(!((int)nod[k].size()<=bsz||mxv[i]<mxv[k]||(mxv[i]==mxv[k]&&i>=k))){
      ans[{i,k}]=ans[{k,i}]=tmp[k];
    }
  }
  while(q--){
    int u=find(read()),v=find(read());
    if(u==v){puts("-1");continue;}
    if(nod[u].size()>nod[v].size())swap(u,v);ll res=0;
    if((int)nod[u].size()<=bsz){
      int t=max(mxv[u],mxv[v]);
      for(int x:nod[u]){
        int ps=upper_bound(vec[v].begin(),vec[v].end(),t-val[x]-1)-vec[v].begin();
        res+=1ll*ps*t+su[v][su[v].size()-1]-(ps?su[v][ps-1]:0)+1ll*(vec[v].size()-ps)*(val[x]+1);
      }
    }else res=ans[{u,v}];
    printf("%.10lf\n",res/(db)nod[u].size()/(db)nod[v].size());
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}