#include <cstdio>

int n,q,tot;
bool vis[2][1000001];
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1,r,c;i<=q;i++){
		scanf("%d%d",&r,&c);
		--r;
		if(vis[r][c]){
			if(vis[r^1][c-1])--tot;
			if(vis[r^1][c])--tot;
			if(vis[r^1][c+1])--tot;
		}
		vis[r][c]^=1;
		if(vis[r][c]){
			if(vis[r^1][c-1])++tot;
			if(vis[r^1][c])++tot;
			if(vis[r^1][c+1])++tot;
		}
		if(tot)puts("No");
		else puts("Yes");
	}
}