// Hydro submission #62cf95be7c441a02fd12b674@1657771454608
#include<bits/stdc++.h>
using namespace std;
int a[1001],b[1001],c[1001],x,y;
bool f[1001];
int main()
{
	int n,i;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>a[i];
	for(i=1;i<=n;i++)
	{
		cin>>b[i];
		if(a[i]!=b[i])
		(x?y:x)=i;
	}
	for(i=1;i<=n;i++)
	if(i!=x&&i!=y)
	c[i]=a[i],f[a[i]]=true;
	if(y) f[a[x]]||f[b[y]]?(c[y]=a[y],c[x]=b[x]):(c[x]=a[x],c[y]=b[y]);
	else for(i=1;i<=n;i++) if(!f[i])
	{
		c[x]=i;
		break;
	}
	for(i=1;i<=n;i++) 
	printf("%d ",c[i]);
	return 0;
}