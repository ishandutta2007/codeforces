#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef double ld;

void solve();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int z=1;
	cin>>z;
	while (z--)
		solve();
	return 0;
}

#define int li

int rec (int a, int b)
{
	//cout<<a<<' '<<b<<endl;
	if (a==0)
		return 1;
	if ( rec (b%a, a)==1 )
		return -1;
	int cnt=0;
	int cur=b/a;
	cur%=(a+1);
	if (cur%2)
		return 1;
	else
		return -1;
}

void solve()
{
	int a, b;
	cin>>a>>b;
	if (a>b)
		swap(a, b);
	int ans=rec(a, b);
	if (ans==1)
		cout<<"Second\n";
	else
		cout<<"First\n";
}