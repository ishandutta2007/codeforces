#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,K;
struct atom{
	double x[128][128];
}A,B,ans;
atom operator * (const atom &k1,const atom &k2){
	memset(B.x,0x00,sizeof B.x);
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			for (int k=0;k<=n;k++)
				B.x[i][j]+=k1.x[i][k]*k2.x[k][j];
	return B;
}
int main(){
	scanf("%d%d",&K,&n);
	for (int i=0;i<=n;i++){
		double k1; scanf("%lf",&k1);
		for (int j=0;j<=127;j++) A.x[j][i^j]=k1;
	}
	n=127;
	ans=A; K--;
	while (K){
		if (K&1) ans=ans*A; A=A*A; K>>=1;
	}
	printf("%.11lf\n",1-ans.x[0][0]);
	return 0;
}