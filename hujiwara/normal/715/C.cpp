#include <bits/stdc++.h>
using namespace std;

const int MN=100000;

int sub[MN];

void cal_sub(int i,int p,vector<vector<int> > &e)
{
  sub[i]=1;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p){
      continue;
    }
    cal_sub(j,i,e);
    sub[i]+=sub[j];
  }
}

int cent(int a,vector<vector<int> > &e)
{
  cal_sub(a,-1,e);
  int n=sub[a];
  int p=-1;
  while(1){
    int S=0,q=-1;
    for(int x=0;x<e[a].size();x++){
      int j=e[a][x];
      if(j==p){
	continue;
      }
      if(S<sub[j]){
	S=sub[j];
	q=j;
      }
    }
    if(S<=n/2){
      break;
    }
    p=a;
    a=q;
  }
  return a;
}

int recon(int i,int p,vector<vector<int> > &e,vector<vector<int> > &d,vector<vector<int> > &ne,vector<vector<int> > &nd,int &N)
{
  int a=N;
  ne.push_back(vector<int>(0));
  nd.push_back(vector<int>(0));
  N++;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    int b=recon(j,i,e,d,ne,nd,N);
    ne[a].push_back(b);
    nd[a].push_back(d[i][x]);
    ne[b].push_back(a);
    nd[b].push_back(d[i][x]);
  }
  return a;
}

long long M;
long long sq(long long a){return a*a%M;}
long long pw(long long a,long long n)
{
  return n==0?1ll:sq(pw(a,n/2))*(n%2==1?a:1ll)%M;
}
long long inv(long long a){return pw(a,M-2);}

long long P1[MN+11],P2[MN+11];
long long R1[MN],R2[MN];

void dfs(int i,int p,long long dep,vector<vector<int> > &e,vector<vector<int> > &d,vector<int> &V)
{
  V.push_back(i);
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    long long D=d[i][x];
    if(j==p)continue;
    R1[j]=(R1[i]+P2[dep+1]*D)%M;
    R2[j]=(R2[i]+P1[dep]*D)%M;
    dfs(j,i,dep+1,e,d,V);
  }
}


long long solve(vector<vector<int> > &e,vector<vector<int> > &d)
{
  int c=cent(0,e);
  long long ans=0;
  vector<pair<long long,int> > p1,p2;
  p1.push_back(make_pair(0,e[c].size()));
  p2.push_back(make_pair(0,e[c].size()));
  for(int x=0;x<e[c].size();x++){
    int i=e[c][x];
    long long D=d[c][x];
    R1[i]=D*P2[1]%M;
    R2[i]=D%M;
    vector<int> V;
    dfs(i,c,1,e,d,V);
    for(int t=0;t<V.size();t++){
      int j=V[t];
      p1.push_back(make_pair(R1[j],x));
      p2.push_back(make_pair(R2[j],x));
    }
  }
  sort(p2.begin(),p2.end());
  for(int t=0;t<p1.size();t++){
    long long r=p1[t].first,mr=(M-r)%M;
    int x=p1[t].second;
    ans+=lower_bound(p2.begin(),p2.end(),make_pair(mr,x))-lower_bound(p2.begin(),p2.end(),make_pair(mr,0));
    ans+=lower_bound(p2.begin(),p2.end(),make_pair(mr+1,0))-upper_bound(p2.begin(),p2.end(),make_pair(mr,x));
  }
  for(int t=0;t<e[c].size();t++){
    int i=e[c][t],N=0;
    vector<vector<int> > ne,nd;
    recon(i,c,e,d,ne,nd,N);
    ans+=solve(ne,nd);
  }
  return ans;
}

pair<long long,long long> exgcd(long long a,long long b)
{
  pair<long long,long long> ret;
  if(b==0){
    ret.first=1;
    ret.second=0;
  }
  else{
    pair<long long,long long> p=exgcd(b,a%b);
    ret.first=p.second;
    ret.second=p.first-(a/b)*p.second;
  }
  return ret;
}

int main()
{
  int n;
  scanf("%d%lld",&n,&M);
  long long r10=exgcd(10,M).first;
  r10%=M;
  if(r10<0){
    r10=(M+r10)%M;
  }
  P1[0]=P2[0]=1ll;
  for(int i=1;i<=n+10;i++){
    P1[i]=P1[i-1]*10%M;
    P2[i]=P2[i-1]*r10%M;
  }
  vector<vector<int> > e(n),d(n);
  for(int i=0;i<n-1;i++){
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    e[u].push_back(v);
    d[u].push_back(w);
    e[v].push_back(u);
    d[v].push_back(w);
  }
  printf("%lld\n",solve(e,d));
  return 0;
}