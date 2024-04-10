#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,a,u[26]={0},ans;
	cin>>n;
	string s;
	cin>>s;
	int m;
	cin>>m;
	string t;
	vector<int> p[26];
	for(int j=0;j<s.size();j++)
	{
		a=s[j];
		p[a-97].push_back(j+1);
	}
	for(int i=0;i<m;i++)
	{
		cin>>t;
		ans=0;
		for(int j=0;j<t.size();j++)
		{
			a=t[j];
			u[a-97]+=1;
		}
		for(int j=0;j<26;j++)
		{
			if(u[j]>0)
			{
				if(p[j][u[j]-1]>ans)
				ans=p[j][u[j]-1];
			}
			u[j]=0;
		}
		cout<<ans<<"\n";
	}
	return 0;
}