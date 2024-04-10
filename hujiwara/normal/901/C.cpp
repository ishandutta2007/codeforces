#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int> > e;

vector<pair<int,int> > cyc;

bool V[300000]={0};
int pr[300000],dep[300000];

void dfs(int i,int p)
{
  //printf("%d %d\n",i,p);
  V[i]=1;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    if(!V[j]){
      pr[j]=i;
      dep[j]=dep[i]+1;
      dfs(j,i);
    }
    else if(dep[j]<dep[i]){
      int mn=i,mx=i,k=i;
      while(k!=j){
	//printf("%d %d %d\n",k,j,i);
	k=pr[k];
	mn=min(mn,k);
	mx=max(mx,k);
      }
      cyc.push_back(make_pair(mn,mx));
    }
  }
}

int main()
{
  scanf("%d%d",&n,&m);
  e=vector<vector<int> >(n);
  for(int i=0;i<m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    a--,b--;
    e[a].push_back(b);
    e[b].push_back(a);
  }
  for(int i=0;i<n;i++){
    if(!V[i]){
      pr[i]=-1;
      dep[i]=0;
      dfs(i,-1);
    }
  }
  static int M[300000];
  for(int i=0;i<n;i++)M[i]=n;
  for(int t=0;t<cyc.size();t++){
    M[cyc[t].first]=min(M[cyc[t].first],cyc[t].second);
  }
  for(int i=n-1;i>0;i--){
    M[i-1]=min(M[i-1],M[i]);
  }
  long long S[300001];
  S[0]=0;
  for(int i=0;i<n;i++){
    S[i+1]=S[i]+M[i];
  }
  int q;
  scanf("%d",&q);
  while(q--){
    int l,r;
    scanf("%d%d",&l,&r);
    l--;
    int k=lower_bound(M,M+n,r)-M;
    k=max(k,l);
    k=min(k,r);
    printf("%lld\n",S[k]-S[l]+(long long)(r-k)*r-(long long)(r-l)*(l+r-1)/2);
  }
  return 0;
}