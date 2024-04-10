#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int main()
{
	pair<int,int> b[1000];
	int a[6],m;
	int ans[6];
	a[0]=4;
	a[1]=8;
	a[2]=15;
	a[3]=16;
	a[4]=23;
	a[5]=42;
	FOR(i,0,6)
	{
		FOR(j,i+1,6)
		{
			b[a[i]*a[j]]=mp(a[i],a[j]);
		}
	}
	cout<<"? 1 2"<<'\n';
	cin>>m;
	int p=b[m].first;
	int q=b[m].second;
	cout<<"? 2 3"<<'\n';
	cin>>m;
	int r=b[m].first;
	int s=b[m].second;
	if(p==r)
	{
		ans[0]=q;
		ans[1]=r;
		ans[2]=s;
	}
	else if(q==r)
	{
		ans[0]=p;
		ans[1]=r;
		ans[2]=s;
	}
	else if(p==s)
	{
		ans[0]=q;
		ans[1]=p;
		ans[2]=r;
	}
	else
	{
		ans[0]=p;
		ans[1]=q;
		ans[2]=r;
	}
	cout<<"? 4 5"<<'\n';
	cin>>m;
	p=b[m].first;
	q=b[m].second;
	cout<<"? 5 6"<<'\n';
	cin>>m;
	r=b[m].first;
	s=b[m].second;
	if(p==r)
	{
		ans[3]=q;
		ans[4]=r;
		ans[5]=s;
	}
	else if(q==r)
	{
		ans[3]=p;
		ans[4]=r;
		ans[5]=s;
	}
	else if(p==s)
	{
		ans[3]=q;
		ans[4]=p;
		ans[5]=r;
	}
	else
	{
		ans[3]=p;
		ans[4]=q;
		ans[5]=r;
	}
	cout<<'!';
	FOR(i,0,6)cout<<' '<<ans[i];
	cout<<'\n';
	return 0;
}