#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=100+5;
int a[N],ans[N];

int main()
{
	int n;
	cin>>n;
	rep(i,1,n)scanf("%d",a+i);
	sort(a+1,a+n+1);
	int i=1,t=0;
	for(;i<=n;i+=2)ans[++t]=a[i];
	if(i-2==n)i=n-1;
	else i=n;
	for(;i;i-=2)ans[++t]=a[i];
	rep(i,1,t)printf("%d ",ans[i]); 
}