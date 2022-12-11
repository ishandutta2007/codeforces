#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[30][30],n,m;
int check(){
	for (int i=1;i<=n;i++){
		int num=0;
		for (int j=1;j<=m;j++) if (A[i][j]!=j) num++;
		if (num>2) return 0;
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) scanf("%d",&A[i][j]);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++){
			for (int k=1;k<=n;k++) swap(A[k][i],A[k][j]);
			if (check()){
				printf("YES\n"); return 0;
			}
			for (int k=1;k<=n;k++) swap(A[k][i],A[k][j]);
		}
	printf("NO\n");
	return 0;
}