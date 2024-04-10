#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
using namespace std;
int a[3][3]={
	{0,1,0},
	{0,0,1},
	{1,0,0}
};
int b[6][6]={
	{0,1,1,1,0,0},
	{0,0,1,0,0,1},
	{0,0,0,1,1,1},
	{0,1,0,0,1,0},
	{1,1,0,0,0,1},
	{1,0,0,1,0,0}
};
int f[1005][1005];
int main()
{
	int n;scanf("%d",&n);
	if(n==4){
		printf("-1\n");
		return 0;
	}
	if(n&1){
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)f[i][j]=a[i][j];
	}else{
		for (int i=0;i<6;i++)
			for (int j=0;j<6;j++)f[i][j]=b[i][j];
	}
	for (int i=n&1?3:6;i<n;i+=2){
		f[i][i+1]=1;
		for (int j=0;j<i;j++)
			f[i+1][j]=1,f[j][i]=1;
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if(j)putchar(' ');
			printf("%d",f[i][j]);
		}
		printf("\n");
	}
	return 0;
}