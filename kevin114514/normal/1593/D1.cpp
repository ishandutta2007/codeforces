#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	if(!b)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k;
		cin>>k;
		int n=0;
		vector<int> v;
		for(int i=0;i<k;i++)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		for(int i=1;i<k;i++)
			n=gcd(n,v[i]-v[i-1]);
		if(!n)
			n=-1;
		cout<<n<<endl;
	}
	return 0;
}
//printf("%02d",...);