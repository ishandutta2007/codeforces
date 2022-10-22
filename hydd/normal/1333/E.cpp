#include<bits/stdc++.h>
using namespace std;
int n,num[510][510];
int main(){
	scanf("%d",&n);
	if (n<=2){ puts("-1"); return 0;}
	num[1][1]=2; num[1][2]=9; num[1][3]=7;
	num[2][1]=3; num[2][2]=6; num[2][3]=4;
	num[3][1]=1; num[3][2]=5; num[3][3]=8;
	int now=0;
	for (int i=4;i<=n;i++)
		if (i&1){
			for (int j=1;j<i;j++) num[j][i]=now--;
			for (int j=i;j>0;j--) num[i][j]=now--;
		} else{
			for (int j=1;j<i;j++) num[i][j]=now--;
			for (int j=i;j>0;j--) num[j][i]=now--;
		}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++)
			printf("%d ",num[i][j]-now);
		putchar('\n');
	}
	return 0;
}