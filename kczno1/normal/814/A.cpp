#include<bits/stdc++.h>
using namespace std;

int a[1000];
bool fuck()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	if(k>1) return 0;
	for(i=1;i<=n;++i)scanf("%d",a+i);
	int x;
	scanf("%d",&x);
	a[0]=-100;
	for(i=1;i<=n;++i)
	{
		if(!a[i])a[i]=x;
		if(a[i]<=a[i-1])return 0;
	}
	return 1;
}

int main()
{
    if(fuck())puts("No");
	else puts("Yes");
}