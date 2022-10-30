#include<bits/stdc++.h>
using namespace std;
long long a[233333];
long long s[233333];
long long ans;
int main()
{
	ios_base::sync_with_stdio(false);
	int T,n;
	long long k;
	string str;
	cin>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+a[i];
		ans=s[n]-k;
		for(int ti=n;ti>1;ti--)
		{
			long long sumrest=s[ti-1]-s[1];
			int cnt=n-ti+1+1;
			//k-sumrest>=cnt*(a[1]-x)
			long long val=a[1]-((k-sumrest+(cnt*(__int128)1000000000000000ll))/cnt-(__int128)1000000000000000ll);
			if(val<0)val=0;
//			cerr<<sumrest<<' '<<k-sumrest<<' '<<((k-sumrest+(cnt*10000000000ll))/cnt-10000000000ll)<<endl;
			ans=min(ans,val+(n-ti+1));
//			cerr<<ti<<' '<<val<<' '<<a[1]-val<<endl;
		}
		cout<<max(ans,0ll)<<endl;
	}
	
	return 0;
}