#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int num[110],n,b[110][110],pre,m;
int main(){
	scanf("%d",&m); n=3;
	while (n*(n-1)*(n-2)/6<=m) n++; n--;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++) b[i][j]=(i!=j);
	int pre=n; m-=n*(n-1)*(n-2)/6;
	while (m){
		n++; int num=2;
		while (num*(num-1)/2<=m&&num<=pre) num++;
		num--;
		for (int i=1;i<=num;i++){
			b[n][i]=1; b[i][n]=1;
		}
		m-=num*(num-1)/2;
	}
	printf("%d\n",n);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++) putchar('0'+b[i][j]); cout<<endl;
	}
}