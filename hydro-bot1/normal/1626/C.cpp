#include<bits/stdc++.h>
using namespace std;
long long hp[233],t[233],st[233];
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	cin>>T;
	while(T--)
	{
		memset(st,-1,sizeof(st));
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>t[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>hp[i];
			st[i]=t[i]-hp[i]+1;
			int j=i-1;
			while(j>=1 and (st[i]<t[j] or (st[i]==t[j] and hp[j]!=1)))st[i]=min(st[i],st[j]),j--;
			j++;
			while(j<i)st[j]=st[i],j++;
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
//			cerr<<i<<' '<<st[i]<<endl;
			if(st[i]!=st[i+1])
				ans+=1ll*(t[i]-st[i]+1)*(t[i]-st[i]+2)/2;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}