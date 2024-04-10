#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,a[505][505],p[20];

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=16;i++){
		p[i]=i*i*i*i;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if((i+j)%2){a[i][j]=720720;}
			else{a[i][j]=p[a[i][j]];a[i][j]+=720720;}
			printf("%d ",a[i][j]);
		}puts("");
	}
}