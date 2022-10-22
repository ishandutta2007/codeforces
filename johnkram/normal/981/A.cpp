#include<bits/stdc++.h>
using namespace std;
char c[50],d[50];
int n,m,l,r,i,ans;
int main()
{
	scanf("%s",c);
	n=strlen(c);
	for(l=0;l<n;l++)for(r=l;r<n;r++)
	{
		m=r-l+1;
		for(i=l;i<=r;i++)d[i-l]=c[i];
		for(i=0;i<m;i++)if(d[i]!=d[m-i-1])break;
		if(i<m)ans=max(ans,m);
	}
	cout<<ans<<endl;
	return 0;
}