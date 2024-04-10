#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
ll ans;
int f[MAXN],d[MAXN],s[MAXN],n,i;
int main()
{
	scanf("%d",&n);
	d[1]=1;
	for(i=2;i<=n;i++)
	{
		scanf("%d",f+i);
		d[i]=d[f[i]]+1;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",s+i);
		if(!~s[i]&&(d[i]&1)||~s[i]&&!(d[i]&1))
		{
			puts("-1");
			return 0;
		}
		if(d[i]&1)if(!~s[f[i]]||s[f[i]]>s[i])s[f[i]]=s[i];
	}
	for(i=1;i<=n;i++)
	{
		if(!~s[i])s[i]=s[f[i]];
		if(s[i]<s[f[i]])
		{
			puts("-1");
			return 0;
		}
		ans+=s[i]-s[f[i]];
	}
	cout<<ans<<endl;
	return 0;
}