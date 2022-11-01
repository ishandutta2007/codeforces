#include <bits/stdc++.h>
using namespace std;

long long dp[100][21][21]={0};
const long long mod=1000000007ll;
void ad(long long &a,long long b){a+=b;a%=mod;}
vector<vector<int> > e;
int n,k;

void dfs(int i,int p)
{
  long long tdp[2][21][21][21]={0};
  bool b=0;
  for(int y=0;y<=k;y++){
    for(int v=0;v<=k;v++){
      tdp[b][y][k][v]=1ll;
    }
  }
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p){
      continue;
    }
    for(int y=0;y<=k;y++){
      for(int z=0;z<=k;z++){
	for(int v=0;v<=k;v++){
	  tdp[!b][y][z][v]=0ll;
	}
      }
    }
    dfs(j,i);
    for(int y=0;y<=k;y++){
      for(int v=0;v<=k;v++){
	int nv=min(v+1,k);
	for(int z=0;z<=k;z++){
	  for(int w=0;w<=k;w++){
	    ad(tdp[!b][y][min(w,z)][v],tdp[b][y][w][v]*dp[j][min(y,nv)][z]%mod);
	  }
	}
      }
    }
    b=!b;
  }
  for(int y=0;y<=k;y++){
    for(int z=0;z<=k;z++){
      if(y<k||z<k){
	int ny=min(y+1,k),nz=min(z+1,k);
	ad(dp[i][y][nz],tdp[b][ny][z][z]);
      }
    }
  }
  for(int y=0;y<=k;y++){
    for(int z=0;z<=k;z++){
      ad(dp[i][y][0],tdp[b][0][z][z]);
    }
  }
}

int main()
{
  scanf("%d%d",&n,&k);
  e=vector<vector<int> >(n);
  for(int t=0;t<n-1;t++){
    int u,v;
    scanf("%d%d",&u,&v);
    u--,v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(0,-1);
  long long ans=0ll;
  for(int z=0;z<=k;z++){
    ad(ans,dp[0][k][z]);
  }
  printf("%d\n",(int)ans);
  return 0;
}