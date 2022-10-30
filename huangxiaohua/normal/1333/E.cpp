#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,a[505][505],sb,cur;

int main(){
	scanf("%d",&n);
	if(n<=2){puts("-1");return 0;}
	a[1][1]=4; a[1][2]=7; a[1][3]=1;
	a[2][1]=3; a[2][2]=5; a[2][3]=2;
	a[3][1]=8; a[3][2]=6; a[3][3]=9;
	sb=n*n-9;
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++){
			a[i][j]+=sb;
		}
	}
	cur=a[1][3];
	for(i=4;i<=n;i++){
		if(!(i&1)){
			for(j=1;j<i;j++){
				cur--;
				a[j][i]=cur;
			}
			for(j=i;j>=1;j--){
				cur--;
				a[i][j]=cur;
			}
		}
		else{
			for(j=1;j<i;j++){
				cur--;
				a[i][j]=cur;
			}
			for(j=i;j>=1;j--){
				cur--;
				a[j][i]=cur;
			}
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}puts("");
	}
}