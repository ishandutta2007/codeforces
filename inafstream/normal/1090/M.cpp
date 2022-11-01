#include <bits/stdc++.h>

using namespace std;

int n,m,i,j,a[100005],s,mx;

int main()
{
	scanf("%d%d",&n,&m);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	
	for (i=1;i<=n;i++)
	{
		if (a[i]==a[i-1]) s=1; else s++;
		
		mx=max(mx,s);
		
	}
	
	cout<<mx<<endl;
	
}