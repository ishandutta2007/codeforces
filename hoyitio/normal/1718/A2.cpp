#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		vector<int> a(n+5),s(n+5);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			s[i]=s[i-1]^a[i];
		}
		map<int,int> mp[2];
		vector<int> f(n+5);
		mp[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=f[i-1]+1;
			if(not mp[0].contains(s[i]))mp[0][s[i]]=-1;
			if(not mp[1].contains(s[i]))mp[1][s[i]]=-1;
			int pre1=mp[0][s[i]],pre2=mp[1][s[i]];
			if(pre1!=-1)
				f[i]=min(f[i],f[pre1]+i-pre1-1);
			if(pre2!=-1)
				f[i]=min(f[i],f[pre2]+i-pre2-1);
			mp[i%2][s[i]]=i;
//			cerr<<i<<' '<<s[i]<<' '<<pre1<<' '<<pre2<<' '<<f[i]<<endl;
		}
		cout<<f[n]<<endl;
	}
	return 0;
}