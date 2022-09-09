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
//#define FILE "fibseq"
//bool flag=true;
int main ()
{
#ifdef DEBUG
	freopen ("in.txt", "r", stdin);
	//freopen ("out.txt", "w", stdout);
	//cout<<FILE<<endl;
#else
	//freopen (FILE ".in", "r", stdin);
	//freopen (FILE ".out", "w", stdout);
#endif

	int t=1;
	while (t--)
		solve();
	return 0;
}

//#define int li

int n, a, b;
vector <int> ans;

void solve()
{
	cin>>n>>a>>b;
	if (n==1)
	{
		cout<<"1";
		return;
	}
	if (b==0)
	{
		if (a==n-1)
		{
			cout<<"-1";
			return;
		}
		cout<<1<<' ';
		cout<<1<<' ';
		for (int i=0; i<a; i++)
			cout<<i+2<<' ';
		for (int i=a+2; i<n; i++)
			cout<<1<<' ';
		return;
	}
	ans.pb(1);
	int cur=1;
	for (int i=0; i<b; i++)
	{
		cur*=2;
		ans.pb(cur);
	}
	for (int i=0; i<a; i++)
		ans.pb ( ++cur );
	for (int i=a+b; i<n; i++)
		ans.pb(1);
	for (int i=0; i<n; i++)
		cout<<ans[i]<<' ';

}