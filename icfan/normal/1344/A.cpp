#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> v(n);
		set<int> s;
		for(int i=0;i<n;i++) 
		{
			cin>>v[i];
			int x=((v[i]+i)%n+n)%n;
			s.insert(x);
		}
		if(s.size()==n) puts("YES");
		else puts("NO");
	}	
}