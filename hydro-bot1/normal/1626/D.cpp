#include<bits/stdc++.h>
using namespace std;
int cnt[233333],s[233333];
int a[233333];
int ansl[23],ansr[23];//0~18
int get(int x)
{
	if(x==0)return 1;
	else if((x&-x)==x)return 0;
	else return (1<<(32-__builtin_clz(x)))-x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		memset(ansl,0,sizeof(ansl));
		memset(ansr,0,sizeof(ansr));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			cnt[a[i]]++;
		}
		for(int i=1;i<=n;i++)s[i]=s[i-1]+cnt[i];
		int ans=0x3f3f3f3f;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=18;j++)
				if(s[i]<=(1<<j))
					ansl[j]=max(ansl[j],s[i]);
		}
		for(int i=n+1;i>=1;i--)
		{
			//>=i
			for(int j=0;j<=18;j++)
				if(s[n]-s[i-1]<=(1<<j))
					ansr[j]=max(ansr[j],s[n]-s[i-1]);
			for(int j=18;j>=0;j--)
			{
				if(ansl[j]==s[i])ansl[j]=s[i-1];
				for(int k=0;k<=18;k++)
				{
					ans=min(ans,get(ansl[j])+get(n-ansr[k]-ansl[j])+get(ansr[k]));
				}
			}
		}
		cout<<ans<<endl;
		/*
		for(int i=n+1;i>=1;i--)
		{
			for(int j=0;j<=18;j++)
				if(s[n]-s[i-1]<=(1<<j))
					ansr[i]=max(ansr[i],s[n]-s[i-1]);
		}
		for(int i=0;i<=18;i++)
			for(int j=0;j<=18;j++)
			{
				if(ansl[i])
				ans=min(ans,(1<<i)-ansl[i]???)
			}
		*/
		
		for(int i=1;i<=n;i++)
		{
			cnt[a[i]]--;
		}
	}
	
	return 0;
}