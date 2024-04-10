#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,t,n,m,a[666][666];

int main(){
	ios::sync_with_stdio(0);
	scanf("%d%d",&n,&m);
	if(n==1&&m==1){puts("0");return 0;}
	if(n==1){
		for(i=1;i<=m;i++){printf("%d ",i+1);}return 0;
	}
	if(m==1){
		for(i=1;i<=n;i++){printf("%d\n",i+1);}return 0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			a[i][j]=j+1;
		}
	}
	for(i=2;i<=n;i++){
		for(j=1;j<=m;j++){
			a[i][j]*=(m+i);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%d ",a[i][j]);
		}puts("");
	}
}