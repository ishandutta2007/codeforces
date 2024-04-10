#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int a[510][510];
int b[510][510];
vector<int> pom1,pom2;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			cin>>b[i][j];
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=min(m,i);j++)
		{
			pom1.push_back(a[i-j+1][j]);
			pom2.push_back(b[i-j+1][j]);
		}
		sort(pom1.begin(),pom1.end());
		sort(pom2.begin(),pom2.end());
		for(j=0;(unsigned)j<pom1.size();j++)
		{
			if(pom1[j]!=pom2[j])
			{
				//cout<<i;
				cout<<"NO";
				return 0;
			}
		}
		pom1.clear();
		pom2.clear();
	}
	for(j=1;j<=m;j++)
	{
		for(i=1;i<=min(n,m-j+1);i++)
		{
			pom1.push_back(a[n-i+1][j+i-1]);
			pom2.push_back(b[n-i+1][j+i-1]);
		}
		sort(pom1.begin(),pom1.end());
		sort(pom2.begin(),pom2.end());
		for(i=0;(unsigned)i<pom1.size();i++)
		{
			if(pom1[i]!=pom2[i])
			{
				//cout<<i;
				cout<<"NO";
				return 0;
			}
		}
		pom1.clear();
		pom2.clear();
	}
	cout<<"YES";
	return 0;
}