#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
void dfs(int x,int y){
	if(a[x][y]!='#'){
		return;
	}
	a[x][y]='.';
	dfs(x-1,y);
	dfs(x+1,y);
	dfs(x,y-1);
	dfs(x,y+1);
}
int main(){
	int n,m,i,j,v,en,em;
	for(scanf("%d%d",&n,&m),i=1;i<=n;i++)scanf("%s",a[i]+1);
	for(en=0,i=1;i<=n;i++){
		for(v=0,j=1;j<=m;j++){
			v+=a[i][j]=='#'&&a[i][j-1]!='#';
		}
		if(v>1){
			puts("-1");
			return 0;
		}
		en+=v==0;
	}
	for(em=0,j=1;j<=m;j++){
		for(v=0,i=1;i<=n;i++){
			v+=a[i][j]=='#'&&a[i-1][j]!='#';
		}
		if(v>1){
			puts("-1");
			return 0;
		}
		em+=v==0;
	}
	if((en&&!em)||(!en&&em)){
		puts("-1");
		return 0;
	}
	for(v=0,i=1;i<=n;i++)for(j=1;j<=m;j++){
		v+=a[i][j]=='#';
		dfs(i,j);
	}
	printf("%d\n",v);
	return 0;
}