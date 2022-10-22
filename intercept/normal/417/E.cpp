#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[109],b[109];
int main(){
 	scanf("%d%d",&n,&m);
 	for(int i=1;i<=n;++i)a[i]=1;
 	if(n&1)a[n]=(n+1)/2,a[1]=2;
 	else a[n]=(n-2)/2;
 	for(int i=1;i<=m;++i)b[i]=1;
 	if(m&1)b[m]=(m+1)/2,b[1]=2;
 	else b[m]=(m-2)/2;
 	if(n==1)a[1]=1;
 	if(m==1)b[1]=1;
 	if(n==2)a[1]=3,a[2]=4;
 	if(m==2)b[1]=3,b[2]=4;
 	for(int i=1;i<=n;++i){
 		for(int j=1;j<=m;++j){
 			printf("%d ",a[i]*b[j]);
		}
		printf("\n");
	}
	return 0;
}