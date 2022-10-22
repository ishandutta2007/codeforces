#include<bits/stdc++.h>
using namespace std;
int n,m,a[110][110]; bool flag;
void print(){
	if (flag)
		for (int i=1;i<=m;i++){
			for (int j=1;j<=n;j++)
				printf("%d ",a[j][i]);
			putchar('\n');
		}
	else
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++)
				printf("%d ",a[i][j]);
			putchar('\n');
		}
}
int main(){
	scanf("%d%d",&n,&m);
	if (n==1&&m==1){ puts("1"); return 0;}
	
	flag=false;
	if (n>m) swap(n,m),flag=true;
	if (m==2||(n==1&&m==3)){ puts("-1"); return 0;}
	
	if (m==3){
		if (n==2){
			a[1][1]=3; a[1][2]=6; a[1][3]=2;
			a[2][1]=5; a[2][2]=1; a[2][3]=4;
		} else{
			a[1][1]=3; a[1][2]=5; a[1][3]=7;
			a[2][1]=8; a[2][2]=1; a[2][3]=9;
			a[3][1]=2; a[3][2]=4; a[3][3]=6;
		}
	} else{
		int cnt=0;
		for (int i=m/2;i>=1;i--) a[1][++cnt]=i,a[1][++cnt]=i+m/2;
		a[1][++cnt]=m;
		for (int i=2;i<=n;i++)
			for (int j=1;j<=m;j++)
				a[i][j]=a[i-1][j]+m;
	}
	print();
	return 0;
}