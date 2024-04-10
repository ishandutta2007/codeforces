#include<bits/stdc++.h>
#define lint long long
#define inf 1e9
#define linf 1e14
using namespace std;
lint a[100100];
lint preSUM[100100];
map<lint,int> appr;
int n;
int k;
lint calc(lint total)
{
	appr.clear();
	lint ret=0;
	for(int i=0;i<=n;i++)
	{
		ret+=appr[preSUM[i]-total];
		appr[preSUM[i]]++;
	}
	return ret;
}
int main()
{
//	freopen("perfume.in","r",stdin);
//	freopen("perfume.out","w",stdout);
	int T;
//	cin>>T;
T=1;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			preSUM[i]=preSUM[i-1]+a[i];
		if(k==1)
		{
			cout<<calc(1)<<endl;
			continue;
		}
		if(k==-1)
		{
			cout<<calc(1)+calc(-1)<<endl;
			continue;
		}
		lint ans=0;
		for(lint i=1;abs(i)<=linf;i*=k)
			ans+=calc(i);
		cout<<ans<<endl;
	}
	return 0;
}