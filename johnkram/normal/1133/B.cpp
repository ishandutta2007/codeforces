#include<bits/stdc++.h>
using namespace std;
int n,m,i,ans,a[105];
int main()
{
	scanf("%d%d",&n,&m);
	while(n--)
	{
		scanf("%d",&i);
		a[i%m]++;
	}
	ans=a[0]/2;
	for(i=1;i<m-i;i++)ans+=min(a[i],a[m-i]);
	if(!(m&1))ans+=a[m>>1]/2;
	cout<<ans*2<<endl;
	return 0;
}