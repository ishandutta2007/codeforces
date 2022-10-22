#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
int n,c[5005],a[5005],i,j,f[5005][5005],k;
int dp(int l,int r)
{
	if(f[l][r]!=-1)
		return f[l][r];
	if(l==r)
		return 0;
	if(a[l]==a[r])
		return f[l][r]=dp(l+1,r-1)+1;
	else
		return f[l][r]=max(dp(l+1,r),dp(l,r-1));
}
int main(){
	cin >> n;
	for(i=1;i<=n;i++)
		cin >> c[i];
	for(i=1;i<=n;)
	{
		for(j=i;c[i]==c[j]&&j<=n;j++);
		a[++k]=c[i];
		i=j;
	}
	memset(f,-1,sizeof(f));
	cout << k-1-dp(1,k);
}