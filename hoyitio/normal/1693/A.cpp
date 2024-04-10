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
		long long s=0;
		int ok=1;
		vector<int> a(n+5);
		int last=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]!=0)last=i;
		}
		for(int i=1;i<=last;i++)
		{
			s+=a[i];
			if(i!=last and s<=0)ok=0;
		}
		if(s!=0)ok=0;
		if(ok)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}