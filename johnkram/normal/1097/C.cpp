#include<bits/stdc++.h>
using namespace std;
char c[500005];
int a[500005],b[500005],n,m,i,j,k,ans;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",c+1);
		m=strlen(c+1);
		for(i=1,j=k=0;i<=m;i++)if(c[i]=='(')k++;
		else if(k)k--;
		else j++;
		if(j&&k)continue;
		if(j)a[j]++;
		else if(k)b[k]++;
		else a[0]++;
	}
	ans=a[0]>>1;
	for(i=1;i<500005;i++)ans+=min(a[i],b[i]);
	cout<<ans<<endl;
	return 0;
}