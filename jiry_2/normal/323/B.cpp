#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int b[1100][1100];
int main(){
	int n; scanf("%d",&n);
	if (n==4) {cout<<-1<<endl; return 0;}
	int pd=(n-1)%2; n-=pd;
	for (int i=1;i<=n;i++)
		for (int j=1;j<n;j++)
			if (j%2==0) b[(i+j-1)%n+1][i]=1; else b[i][(i+j-1)%n+1]=1;
	if (pd){
		n++;
		b[n][1]=1; b[n][2]=1; for (int i=3;i<n;i++) b[i][n]=1;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) printf("%d ",b[i][j]); printf("\n");
	}
	return 0;
}