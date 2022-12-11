#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int A[110000],n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&A[i]);
	sort(A+1,A+n+1);
	int l=1,r=n;
	while (l<=n&&A[l]==A[1]) l++;
	while (r&&A[r]==A[n]) r--;
	printf("%d\n",max(0,r-l+1));
	return 0;
}