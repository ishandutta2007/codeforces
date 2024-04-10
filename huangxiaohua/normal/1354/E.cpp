#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[4],c[5050],id[5050],it,b[5050][2],res[5050];
vector<int> v[5050];
bool vis[5050][5050];

void dfs(int x){
	id[x]=it;
	b[it][c[x]]++;
	for(auto i:v[x]){
		if(c[i]==c[x]){
			puts("NO");exit(0);
		}
		c[i]=1-c[x];
		if(!id[i])dfs(i);
	}
}

bool dfs2(int x,int y){
	if(x>it)return (y==a[2]);
	if(y>a[2]||vis[x][y])return 0;
	vis[x][y]=1;
	if(dfs2(x+1,y+b[x][0])){
		for(int i=1;i<=n;i++){
			if(id[i]==x&&!c[i])res[i]=2;
		}
		return 1;
	}
	if(dfs2(x+1,y+b[x][1])){
		for(int i=1;i<=n;i++){
			if(id[i]==x&&c[i])res[i]=2;
		}
		return 1;
	}
	return 0;
}

int main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&a[1],&a[2],&a[3]);
	for(i=1;i<=m;i++){
		scanf("%d%d",&j,&k);
		v[j].push_back(k);
		v[k].push_back(j);
	}
	memset(c,-1,sizeof(c));
	for(i=1;i<=n;i++){
		if(!id[i]){
			id[i]=++it;c[i]=0;
			dfs(i);
		}
	}
	if(!dfs2(1,0)){
		puts("NO");return 0;
	}
	puts("YES");
	for(i=1;i<=n;i++){
		if(!res[i]){
			if(a[1]){a[1]--;res[i]=1;}
			else res[i]=3;
		}
		printf("%d",res[i]);
	}
}