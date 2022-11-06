#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
ll a[150000];
ll tree[1000000];
bool build(int n,int l,int r)
{
	if(l==r)
	{
		tree[n]=a[l];
		return 1;
	}
	int m=(l+r)/2;
	build(2*n,l,m);
	bool f=build(2*n+1,m+1,r);
	if(f)
		tree[n]=(tree[2*n] |tree[2*n+1]);
	else
		tree[n]=(tree[2*n] ^ tree[2*n+1]);
	return(!f);
}
bool update(int n,int l,int r,int p,ll b)
{
	if(l==r)
	{
		tree[n]=b;
		return 1;
	}
	int m=(l+r)/2;
	bool f;
	if(p<=m)
	f=update(2*n,l,m,p,b);
	else
	f=update(2*n+1,m+1,r,p,b);
	if(f)
		tree[n]=(tree[2*n] | tree[2*n+1]);
	else
		tree[n]=(tree[2*n] ^ tree[2*n+1]);
	return(!f);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while(t--)
	{
			int n,m;
			cin>>n>>m;
			ll o=pow(2,n);
			FOR(i,0,o)
			cin>>a[i];
			o--;
			build(1,0,o);
			ll p,b;
			FOR(i,0,m)
			{
				cin>>p>>b;
				update(1,0,o,p-1,b);
				cout<<tree[1]<<'\n';
			}
	}
	return 0;
}