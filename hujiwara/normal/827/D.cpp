#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > e;
const int NMAX=200000,INF=1500000000;
int Par[NMAX],Dep[NMAX],X[NMAX],dep[NMAX],par[NMAX],S[NMAX];

void dfs(int i,int p)
{
  dep[i]=(p==-1?0:dep[p]+1);
  par[i]=p;
  S[i]=0;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    dfs(j,i);
    S[i]+=S[j];
  }
}

void HLD()
{
  dfs(0,-1);
  int NX=0;
  Par[0]=0;
  Dep[0]=0;
  stack<int> ST;
  ST.push(0);
  while(!ST.empty()){
    int i=ST.top();
    ST.pop();
    X[i]=NX;
    NX++;
    int K=-1;
    for(int j=0;j<e[i].size();j++){
      int k=e[i][j];
      if(k==par[i])continue;
      if(K==-1||S[K]<S[k]){
	K=k;
      }
    }
    if(K==-1)continue;
    Par[K]=Par[i];
    Dep[K]=Dep[i]+1;
    for(int j=0;j<e[i].size();j++){
      int k=e[i][j];
      if(k==par[i]||k==K){
	continue;
      }
      Par[k]=k;
      Dep[k]=0;
      ST.push(k);
    }
    ST.push(K);
  }
}
int rt(int *uf,int i)
{
  return uf[i]<0?i:uf[i]=rt(uf,uf[i]);
}

void con(int *uf,int a,int b)
{
  if(-uf[a]<-uf[b]){
    uf[a]=b;
  }
  else if(-uf[a]>-uf[b]){
    uf[b]=a;
  }
  else{
    uf[a]=b;
    uf[b]--;
  }
}
template<class T> class segmaxtree
{
private:
  T ragin(int i,int j,int k,int a,int b)
  {
    return a<=j&&k<=b?seg[i]:k<=a||b<=j?-INF:max(ragin(2*i,j,(j+k)/2,a,b),ragin(2*i+1,(j+k)/2,k,a,b));
  }
public:
  T *seg;
  int S;
  segmaxtree(int BS){
    S=BS;
    seg=(T *)calloc(sizeof(T),1<<(S+1));
  }
  void set(int i,T k){
    int p=i+(1<<S);
    seg[p]=k;
    while(p>1){
      p/=2;
      seg[p]=max(seg[2*p],seg[2*p+1]);
    }
  }
  T rag(int a,int b){
    return ragin(1,0,1<<S,a,b);
  }
  T val(int i){
    int p=i+(1<<S);
    return seg[p];
  }
};
template<class T> class seglemintree
{
private:
  void ragin(int i,int j,int k,int a,int b,T v)
  {
    if(a<=j&&k<=b){
      seg[i]=min(seg[i],v);
    }
    else if(a<k&&j<b){
      ragin(2*i,j,(j+k)/2,a,b,v);
      ragin(2*i+1,(j+k)/2,k,a,b,v);
    }
  }
public:
  T *seg;
  int S;
  seglemintree(int BS){
    S=BS;
    seg=(T *)calloc(sizeof(T),1<<(S+1));
  }
  T val(int i){
    int p=i+(1<<S);
    T ret=INF;
    while(p>0){
      ret=min(ret,seg[p]);
      p/=2;
    }
    return ret;
  }
  void rag(int a,int b,T v){
    return ragin(1,0,1<<S,a,b,v);
  }
};

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static pair<pair<int,int>,pair<int,int> > E[200000];
  for(int i=0;i<m;i++){
    int v,u,c;
    scanf("%d%d%d",&v,&u,&c);
    v--,u--;
    E[i]=make_pair(make_pair(c,i),make_pair(v,u));
  }
  sort(E,E+m);
  static int uf[NMAX];
  for(int i=0;i<n;i++)uf[i]=-1;
  e=vector<vector<int> >(n);
  static bool use[200000]={0};
  for(int t=0;t<m;t++){
    int a=E[t].second.first,b=E[t].second.second;
    int ra=rt(uf,a),rb=rt(uf,b);
    if(ra!=rb){
      con(uf,ra,rb);
      e[a].push_back(b);
      e[b].push_back(a);
      use[t]=1;
    }
  }
  HLD();
  /*for(int i=0;i<n;i++){
    printf("%d %d %d %d\n",i+1,X[i],Par[i],Dep[i]);
    }*/
  segmaxtree<int> seg1(18);
  seglemintree<int> seg2(18);
  for(int i=0;i<1<<19;i++){
    seg1.seg[i]=-INF;
    seg2.seg[i]=INF;
  }
  for(int t=0;t<m;t++){
    int a=E[t].second.first,b=E[t].second.second,c=E[t].first.first;
    if(use[t]){
      if(dep[a]>dep[b]){
	swap(a,b);
      }
      seg1.set(X[b],c);
    }
    else{
      //printf("%d %d\n",a,b);
      int T=0;
      while(Par[a]!=Par[b]){
	if(dep[Par[a]]>dep[Par[b]]){
	  seg2.rag(X[a]-Dep[a],X[a]+1,c);
	  assert(0<=a&&a<n&&S[par[Par[a]]]>=2*S[a]);
	  a=par[Par[a]];
	}
	else{
	  seg2.rag(X[b]-Dep[b],X[b]+1,c);
	  b=par[Par[b]];
	}
      }
      if(Dep[a]>Dep[b]){
	seg2.rag(X[b]+1,X[a]+1,c);
	//printf("%d %d %d\n",X[a]-Dep[a]+Dep[b]+1,X[a]+1,c);
      }
      else{
	seg2.rag(X[a]+1,X[b]+1,c);
      }
    }
  }
  int ans[NMAX];
  for(int t=0;t<m;t++){
    int id=E[t].first.second,a=E[t].second.first,b=E[t].second.second;
    if(use[t]){
      if(dep[a]>dep[b]){
	swap(a,b);
      }
      ans[id]=seg2.val(X[b]);
      //intf("%d %d\n",X[b],ans[id]);
    }
    else{
      int A=-INF;
      while(Par[a]!=Par[b]){
	if(dep[Par[a]]>dep[Par[b]]){
	  A=max(A,seg1.rag(X[a]-Dep[a],X[a]+1));
	  a=par[Par[a]];
	}
	else{
	  A=max(A,seg1.rag(X[b]-Dep[b],X[b]+1));
	  b=par[Par[b]];
	}
      }
      if(Dep[a]>Dep[b]){
	A=max(A,seg1.rag(X[b]+1,X[a]+1));
      }
      else{
	A=max(A,seg1.rag(X[a]+1,X[b]+1));
      }
      ans[id]=A;
    }
  }
  for(int i=0;i<m;i++){
    printf("%d ",ans[i]==INF?-1:ans[i]-1);
  }
  putchar('\n');
  return 0;
}