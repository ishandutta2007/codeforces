#include <bits/stdc++.h>
#define SIZE 200005
using namespace std;
int A[SIZE],B[SIZE];
int ta,tb;
int n,m,k;

bool check(int x)
{
	if(x<=k) return true;
	int to=0;
	for(int i=0;i<x;i++)
	{
		while(to<n&&A[to]+ta<=B[i]) to++;
		if(to+(x-i-1)<=k) return true;
	}
	return false;
}
int main()
{
	scanf("%d %d %d %d %d",&n,&m,&ta,&tb,&k);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	for(int i=0;i<m;i++) scanf("%d",&B[i]);
	int l=0,r=m+1;
	while(r-l>1)
	{
		int d=(l+r)/2;
		if(check(d)) l=d;
		else r=d;
	}
	if(l==m) puts("-1");
	else printf("%d\n",B[l]+tb);
	return 0;
}