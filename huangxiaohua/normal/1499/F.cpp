#include <bits/stdc++.h>
using namespace std;
#define M 998244353
typedef long long ll;
int i,j,k,n,m,x,y,a[5050];
ll dp[5050][5050],tmp[5050],res,sum[5050];

vector<int> v[5050];

void dfs(int x,int fa){
	int i,j,k;
	dp[x][0]=a[x]=1;
	for(auto i:v[x]){
		if(i==fa){continue;}
		dfs(i,x);
		a[x]+=a[i];
		memset(tmp,0,sizeof(tmp));
		
		for(j=0;j<=m;j++){
			if(!dp[x][j]){break;}
			for(k=0;k<=m;k++){
				if(!dp[i][k]||j+k+1>m){break;}
				tmp[max(j,k+1)]+=dp[x][j]*dp[i][k];
				tmp[max(j,k+1)]%=M;
			}
		}
		for(j=0;j<=m;j++){
			dp[x][j]=(dp[x][j]*sum[i]+tmp[j])%M;
		}
	}
	for(i=0;i<=m;i++){
		sum[x]+=dp[x][i];
		//printf("%d %d %d\n",x,i,dp[x][i]);
	}
	sum[x]%=M;
}

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	printf("%lld",sum[1]);
}