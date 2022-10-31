#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int i,j,k,n,t,m,a[505][505],tmp,res[505],yes;
 
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
		tmp^=a[i][1];res[i]=1;
	}
	if(tmp){
		yes=1;goto aaa;
	}
	for(i=1;i<=n;i++){
		for(j=2;j<=m;j++){
			if(a[i][j]!=a[i][1]){
				yes=1;res[i]=j;goto aaa;
			}
		}
	}
	aaa:if(yes){
		puts("TAK");
		for(i=1;i<=n;i++){
			printf("%d ",res[i]);
		}return 0;
	}
	puts("NIE");
}