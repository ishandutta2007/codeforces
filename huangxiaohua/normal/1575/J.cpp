#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t,a[1005][1005],dx,dy;
char c;

void dfs(int x,int y){
	if(x>n){
		printf("%d ",y);return;
	}
	if(a[x][y]==1){dx=0;dy=1;}
	if(a[x][y]==2){dx=1;dy=0;}
	if(a[x][y]==3){dx=0;dy=-1;}
	a[x][y]=2;
	dfs(x+dx,y+dy);
}

int main(){
	ios::sync_with_stdio(0);
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			c=getchar();
			if(c=='1'){a[i][j]=1;continue;}
			if(c=='2'){a[i][j]=2;continue;}
			if(c=='3'){a[i][j]=3;continue;}
			j--;
		}
	}
	while(t--){
		scanf("%d",&k);
		dfs(1,k);
	}
}