#include <cstdio>

int d,n,m,x,y;
int main(){
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(y-x<=d&&y-x>=-d&&x+y>=d&&x+y<=n+n-d)puts("YES");
		else puts("NO");
	}
}