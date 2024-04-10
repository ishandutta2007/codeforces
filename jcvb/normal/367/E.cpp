#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<iostream>
#define mo 1000000007
using namespace std;
int n,m,x;
int f[2][400][400]={0};
inline int F(int i,int j,int k){
	return f[i&1][j][k];
}
inline void upd(int i,int j,int k,int x){
	f[i&1][j][k]+=x;
	if(f[i&1][j][k]>=mo)f[i&1][j][k]-=mo;
}
int main()
{
	scanf("%d%d%d",&n,&m,&x);
	if(n>m){
		printf("0\n");
		return 0;
	}
	f[0][0][0]=1;
	for (int i=0;i<m;i++){
		for (int j=0;j<=n;j++)for (int k=0;k<=n;k++)f[(i&1)^1][j][k]=0;
		for (int j=0;j<=n;j++)
			for (int k=0;k<=j;k++){
				int tmp=F(i,j,k);
				if(j+1<=n){
					upd(i+1,j+1,k,tmp);
					upd(i+1,j+1,k+1,tmp);
				}
				if(i+1!=x){
					if(k>0)upd(i+1,j,k-1,tmp);
					upd(i+1,j,k,tmp);
				}
			}
	}
	int an=F(m,n,0);
	for (int i=1;i<=n;i++)an=1ll*an*i%mo;
	printf("%d\n",an);
	return 0;
}