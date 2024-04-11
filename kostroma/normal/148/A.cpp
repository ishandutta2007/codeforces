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

int k, l, m, n, d;

void solve()
{
	cin>>k>>l>>m>>n>>d;
	int ans=0;
	for (int i=1; i<=d; i++)
	if ( i%k==0 || i%l==0 || i%m==0 || i%n==0 )
	ans++;
	cout<<ans;

}