#include <bits/stdc++.h>
using namespace std;

const double EPS=1e-8;
const int INF=10000;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  vector<vector<int> > e(n);
  static int d[400][400];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      d[i][j]=(i==j?0:INF);
    }
  }
  for(int t=0;t<m;t++){
    int u,v;
    scanf("%d%d",&u,&v);
    u--,v--;
    d[u][v]=d[v][u]=1;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
	d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  pair<int,int> V[400][400];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      V[i][j]=make_pair(d[i][j],j);
    }
    sort(V[i],V[i]+n);
  }
  double ans=0;
  for(int i=0;i<n;i++){
    int N[400]={0};
    for(int j=0;j<n;j++){
      N[d[i][j]]++;
    }
    double P[400]={0};
    for(int a=0;a<n;a++){
      P[a]=(N[a]>0?1./N[a]:0);
    }
    double Q[400][3]={0};
    for(int j=0;j<n;j++){
      double p=1./N[d[i][j]]/e[j].size();
      for(int x=0;x<e[j].size();x++){
	int k=e[j][x];
	if(d[i][k]==d[i][j]+1){
	  Q[k][0]+=p;
	}
	else if(d[i][k]==d[i][j]){
	  Q[k][1]+=p;
	}
	else if(d[i][k]==d[i][j]-1){
	  Q[k][2]+=p;
	}
      }
    }
    for(int k=0;k<n;k++){
      double PP[400]={0};
      int D[400];
      for(int a=0;a<n;a++){
	D[a]=-1;
      }
      double MP[400]={0};
      for(int t=0;t<n;t++){
	int j=V[k][t].second;
	for(int s=0;s<3;s++){
	  if(Q[j][s]>EPS){
	    int a=d[i][j]-1+s;
	    if(D[a]<V[k][t].first){
	      PP[a]+=MP[a];
	      D[a]=V[k][t].first;
	      MP[a]=Q[j][s];
	    }
	    else{
	      MP[a]=max(MP[a],Q[j][s]);
	    }
	  }
	}
      }
      for(int a=0;a<n;a++){
	if(D[a]!=-1){
	  PP[a]+=MP[a];
	}
	P[a]=max(P[a],PP[a]);
      }
    }
    double pp=0;
    for(int a=0;a<n;a++){
      pp+=(double)N[a]/n*P[a];
    }
    ans=max(ans,pp);
  }
  printf("%.9lf\n",ans);
  return 0;
}