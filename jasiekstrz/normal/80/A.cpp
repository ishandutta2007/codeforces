#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
bool czy(int x)
{
	int i;
	for(i=2;i*i<=x;i++)
	{
		if(x%i==0)
			return false;
	}
	return true;
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,i;
	cin>>n>>m;
	for(i=n+1;i<m;i++)
	{
		if(czy(i))
		{
			cout<<"NO";
			return 0;
		}
	}
	if(czy(m))
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}