#include<bits/stdc++.h>
using namespace std;
char s[200005];
int n,i,j,k,ans;
int main()
{
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<n;i++)s[i+n]=s[i];
	for(i=0;i<n;i++)if(s[i]==s[i+1])break;
	if(i==n)ans=n;
	else for(j=i+1;j<=i+n;j++)
	{
		if(s[j]==s[j-1])k=0;
		ans=max(ans,++k);
	}
	cout<<ans<<endl;
	return 0;
}