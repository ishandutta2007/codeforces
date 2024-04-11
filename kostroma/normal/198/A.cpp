

// for CodeChef: WHAT'S WRONG WITH YOU GUYS??? WTF IS PENTIUM 3??? PLEASE UPGRADE SERVERS! IT'S RIDICULOUS TO TEST SOLUTIONS ON 9-YEAR OLD SYSTEM!

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <memory.h>
#include <map>

using namespace std;

#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb push_back

typedef pair <int, int> pi;
typedef long long li;
typedef double ld;
#define FILE "change me!"

void solve();
//int timer=0;
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
	//freopen ("out.txt", "w", stdout);
#else
	//freopen ("in.txt", "r", stdin);
	//freopen ("out.txt", "w", stdout);
	//freopen (FILE ".in", "r", stdin);
	//freopen (FILE ".out", "w", stdout);
#endif
	int z=1;
	ios_base::sync_with_stdio(false);
	//cin>>z;
	while (z--)
		solve();
	return 0;
}


//const int MAXN=100500;
#define int li

int k, b, t, n;

bool more (int val)
{
	//cout<<val<<' '<<n<<endl;
	int s=1;
	int ans=0;
	for (int i=0; i<n-val; i++)
	{
		ans+=b*s;
		//cout<<ans<<endl;
		s*=k;
		if (ans>100000000)
			return true;
	}
	ans+=s;
	return ans>t;
}

void solve()
{
	cin>>k>>b>>n>>t;
	int l=-1, r=n;
	while (l+1<r)
	{
		int m=l+r; m>>=1;
		if ( more(m) )
			l=m;
		else
			r=m;
	}
	cout<<r;
}