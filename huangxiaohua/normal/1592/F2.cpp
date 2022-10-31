#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,sum,res,result[505];
bool b[505][505],a[505][505],vis[505];
vector<int> v[505];

bool dfs(int u){
	for(auto i:v[u]){
		if(!vis[i]){
			vis[i]=1;
			if(!result[i]||dfs(result[i])){
				result[i]=u;
				return 1;
			}
		}
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			char c=getchar();
			b[i][j]=(c=='B');
			j-=(c!='W'&&c!='B');
		}
	}
	for(i=n;i>=1;i--){
		for(j=m;j>=1;j--){
			a[i][j]=(b[i][j]^b[i+1][j]^b[i][j+1]^b[i+1][j+1]);
			sum+=a[i][j];
			if(i==n||j==m)continue;
			if((a[i][j]+a[n][j]+a[i][m])==3){
				v[i].push_back(j);
			}
		}
	}
	for(i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i))res++;
	}
	if((res&1)==a[n][m])res+=a[n][m];
	else res-=1-a[n][m];
	printf("%d",sum-res);
}