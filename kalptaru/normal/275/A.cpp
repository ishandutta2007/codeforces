#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int l[5][5],t;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			l[i][j]=1;
		}
	}
	for(int i=1;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			cin>>t;
			l[i][j]+=t;
			l[i+1][j]+=t;
			l[i-1][j]+=t;
			l[i][j+1]+=t;
			l[i][j-1]+=t;
		}
	}
	for(int i=1;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			cout<<(l[i][j]%2);
		}
		cout<<'\n';
	}
	return 0;
}