#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <queue>
#include <time.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef vector <int> vi;

void solve();

int main ()
{
#ifdef DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	//cin>>t;
	while (t--)
		solve();
	return 0;
}

#define int li

int n, m, k;
int mod=1000000007;

int pow (int q, int w)
{
	if (!w)
		return 1;
	if (w%2)
		return (q*pow(q, w-1))%mod;
	int u=pow(q, w/2);
	return (u*u)%mod;
}

void solve()
{
	cin>>n>>m>>k;
	if (k>n)
	{
		int ans=pow(m, n);
		cout<<ans;
		return;
	}
	if (k==n)
	{
		int l=n+1; l/=2;
		int ans=pow(m, l);
		cout<<ans;
		return;
	}
	if (k==1)
	{
		int ans=pow(m, n);
		cout<<ans;
		return;
	}
	if (k%2==0)
	{
	cout<<m;
	return;
	}
	cout<<(m*m)%mod;


}