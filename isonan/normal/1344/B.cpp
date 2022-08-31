#include <cstdio>
#include <algorithm>

int n,m,cnt1,cnt2;
bool map[1001][1001],vis[1001][1001];
bool get(){
	char ch=getchar();
	while(ch!='.'&&ch!='#')ch=getchar();
	return (ch=='#');
}
void dfs(int x,int y){
	if(vis[x][y]||!map[x][y])return;
	vis[x][y]=1;
	if(x>1)dfs(x-1,y);
	if(y>1)dfs(x,y-1);
	if(x<n)dfs(x+1,y);
	if(y<m)dfs(x,y+1);
}
int main(){
	scanf("%d%d",&n,&m);
	int all=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			all+=(map[i][j]=get());
	if(!all){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		int l=m+1,r=0;
		for(int j=1;j<=m;j++)
			if(map[i][j])l=std::min(l,j),r=std::max(r,j);
		if(!r){++cnt1;
		}
		for(int j=l;j<=r;j++)
			if(!map[i][j]){
				puts("-1");
				return 0;
			}
	}
	for(int j=1;j<=m;j++){
		int l=n+1,r=0;
		for(int i=1;i<=n;i++)
			if(map[i][j])l=std::min(l,i),r=std::max(r,i);
		if(!r){++cnt2;
		}
		for(int i=l;i<=r;i++)
			if(!map[i][j]){
				puts("-1");
				return 0;
			}
	}
	if((cnt1!=0)^(cnt2!=0)){
		puts("-1");
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!vis[i][j]&&map[i][j]){
				++cnt;
				dfs(i,j);
			}
	printf("%d\n",cnt);
}