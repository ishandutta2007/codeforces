#include<bits/stdc++.h>
using namespace std;

int i,j,k,n,m,t,res,r2;
bool b[505][505],a[505][505];

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			char c=getchar();
			b[i][j]=(c=='B');
			j-=(c!='W'&&c!='B');
		}
	}
	for(i=n;i>=1;i--){
		for(j=m;j>=1;j--){
			a[i][j]=(b[i][j]^b[i+1][j]^b[i][j+1]^b[i+1][j+1]);
			res+=a[i][j];
			if(i!=n&&j!=m&&a[i][j]&&a[n][m]&&a[n][j]&&a[i][m])r2=1;
		}
	}
	printf("%d",res-r2);
}