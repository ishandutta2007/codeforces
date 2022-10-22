#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=4e5+10,P=1e9+7;
char S[maxn],T[maxn];int tpn,n,q,num[maxn],pw10[maxn],go[maxn],mp[maxn],lg[maxn];vector<int>vec;

struct RMQ{
  int A[maxn],st[19][maxn];
  int cmp(int x,int y){return A[x]<A[y]?x:y;}
  int query(int l,int r){
    int k=lg[r-l+1];
    return cmp(st[k][l],st[k][r-(1<<k)+1]);
  }
  void build(){
    rep(i,0,tpn)lg[i]=lg[i>>1]+(i>1),st[0][i]=i;
    rep(i,1,18)rep(j,0,tpn-(1<<i)+1)st[i][j]=cmp(st[i-1][j],st[i-1][j+(1<<(i-1))]);
  }
}bra,pr;

int query_num(int l,int r){
  return(num[r]+1ll*num[l-1]*(P-pw10[r-l+1]))%P;
}

struct node{
  int mu,ad;
  node():mu(1),ad(0){}
  node(int _m,int _a):mu(_m),ad(_a){}
  node operator+(const node&o)const{
    return node(1ll*mu*o.mu%P,(1ll*ad*o.mu+o.ad)%P);
  }
}lef[19][maxn],rig[19][maxn];
int rt,fa[19][maxn],ls[maxn],rs[maxn],sum[maxn],dep[maxn],L[maxn];

void build(int&rt,int l,int r){
  rt=pr.query(l,r),L[rt]=l;
  sum[rt]=pr.A[rt]<=tpn?build(ls[rt],l,rt-1),build(rs[rt],rt+1,r),S[rt]=='+'?(sum[ls[rt]]+sum[rs[rt]])%P:1ll*sum[ls[rt]]*sum[rs[rt]]%P:query_num(L[rt]=l,r);
}
void dfs(int u,int f){
  fa[0][u]=f,dep[u]=dep[f]+1;
  int v=sum[ls[f]^rs[f]^u];
  node tp=S[f]=='+'?node{1,v}:node{v,0};
  if(f)u==ls[f]?lef[0][u]=tp:rig[0][u]=tp;
  rep(i,1,18){
    fa[i][u]=fa[i-1][fa[i-1][u]];
    lef[i][u]=lef[i-1][u]+lef[i-1][fa[i-1][u]];
    rig[i][u]=rig[i-1][u]+rig[i-1][fa[i-1][u]];
  }
  if(ls[u])dfs(ls[u],u),dfs(rs[u],u);
}

int main(){
  scanf("%s%d",T+1,&q),tpn=strlen(T+1),pw10[0]=1;
  int now=0;
  rep(i,1,tpn){
    pw10[i]=10ll*pw10[i-1]%P;
    bool f1=T[i]=='(',f2=T[i]==')';
    if(f1||f2)now+=f1-f2;
    else{
      S[++n]=T[i],pr.A[n]=T[i]=='+'?now*2:T[i]=='*'?now*2+1:tpn+1;
      num[n]=(10ll*num[n-1]+P+T[i]-48)%P;if(isdigit(T[i]))vec.push_back(n);
    }
    bra.A[i]=now,mp[i]=n;
  }
  per(i,n,1)go[i]=isdigit(S[i+1])?go[i+1]:i;
  bra.build(),pr.build(),build(rt,1,n),dfs(rt,0);
  while(q--){
    int l,r;scanf("%d%d",&l,&r);
    if(T[l]=='+'||T[l]=='*'||T[r]=='+'||T[r]=='*'||bra.A[l-1]!=bra.A[r]||bra.query(l-1,r)!=r){
      puts("-1");continue;
    }
    l=mp[l-1]+1,r=mp[r];
    if(pr.A[pr.query(l,r)]>tpn){
      printf("%d\n",query_num(l,r));continue;
    }
    int u=go[*lower_bound(vec.begin(),vec.end(),l)];
    int v=go[*--upper_bound(vec.begin(),vec.end(),r)];
    int x=query_num(max(L[u],l),u),y=query_num(L[v],min(v,r));node p,q;
    per(i,18,0){
      if(dep[u]-(1<<i)>=dep[v])p=p+lef[i][u],u=fa[i][u];
      if(dep[v]-(1<<i)>=dep[u])q=q+rig[i][v],v=fa[i][v];
    }
    per(i,18,0)if(fa[i][u]!=fa[i][v]){
      p=p+lef[i][u],q=q+rig[i][v],u=fa[i][u],v=fa[i][v];
    }
    x=(1ll*x*p.mu+p.ad)%P,y=(1ll*y*q.mu+q.ad)%P;
    int anc=fa[0][u],res=S[anc]=='+'?(x+y)%P:1ll*x*y%P;
    printf("%d\n",res);
  }
  return 0;
}