#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m,i,j;
char mp[1000005];
vector<int> pos;
int id(int x,int y)
{
	return (x-1)*m+y;
}

int main()
{
	cin>>n>>m;
	rep(i,n)rep(j,m)cin>>mp[id(i,j)];
	rep(i,m-1)
	{
		rep(j,n-1) if(mp[id(j+1,i)]=='X'&&mp[id(j,i+1)]=='X')
		{
			pos.push_back(i);
			break;
		}
	}
	
	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		if(lower_bound(pos.begin(),pos.end(),l)==lower_bound(pos.begin(),pos.end(),r)) puts("YES"); else puts("NO");
	}
	return 0;
}