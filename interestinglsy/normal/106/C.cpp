/*
codeforces-106C
===================================================
Problem
	nmia[i]b[i]c[i]
	d[i]
	c0d0 
Input 
	n, m, c0, d0 .
	n,mmc0c0d0d0
	ai,bi,ci,di
	aiiaibiibi
	ciici,didi
Output
	 
===================================================
Label
	[DP][]
Algorithm-Explain
	
		n
		ci
		ai/bi
		di 
Status
	WA
===================================================
*/
#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
using namespace std;

int n,m,i,j,k;
int a[13],b[13],c[13],d[13];
int dp[99999]; 

int main(){
	memset(dp,0,sizeof(dp));
	a[0]=99999;b[0]=1;
	//freopen("input-106C.txt","r",stdin);
	scanf("%d %d %d %d",&n,&m,&c[0],&d[0]);
	for(i=1;i<=m;i++)scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
	
	for(i=0;i<=m;i++)
		for(j=1;j<=a[i]/b[i];j++)
			for(k=n;k>=c[i];k--)
				dp[k] = max(dp[k],dp[k-c[i]]+d[i]);
				
	cout<<dp[n]<<endl;
	return 0;
}