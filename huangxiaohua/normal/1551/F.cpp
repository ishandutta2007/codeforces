#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,t,sum,vis[150],x,y,it;

ll f[105],res,f2[105][105];
vector<int> v[205];

void dfs(int x,int fa,int d){
	vis[x]=1;
	if(d==j){f[x]++;return;}
	for(auto i:v[x]){
		if(i==fa){continue;}
		dfs(i,x,d+1);
		f[x]+=f[i];
	}
}

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++){
			v[i].clear();
		}
		for(i=1;i<n;i++){
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(m==2){
			printf("%d\n",n*(n-1)/2);continue;
		}
		res=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				memset(vis,0,sizeof(vis));
				memset(f,0,sizeof(f));
				memset(f2,0,sizeof(f2));
				dfs(i,0,0);
				f2[0][0]=1;
				it=0;
				for(auto jj:v[i]){
					if(f[jj]==0){continue;}
					for(k=0;k<=it;k++){
						f2[it][k]%=M;
						f2[it+1][k]+=f2[it][k];
						f2[it+1][k+1]+=f2[it][k]*f[jj]%M;
					}
					it++;
				}
				res+=f2[it][m];res%=M;
			}
		}
		
		printf("%lld\n",res);
	}
}