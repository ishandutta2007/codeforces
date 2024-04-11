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

int ww, bb;
ld dp[1050][1050];

ld eps=1e-10;

ld cnt ( int w, int b, int who )
{
	if (w<0 || b<0)
		return 0.0;
	if ( fabs(dp[w][b]+1)>eps )
		return dp[w][b];

	ld ans=0.0;

	if (w+b==0)
	{
		if ( who==0 )
		return 0.0;
		else
		return 1.0;
	}

	if (w==0)
	return 0.0;
	if (b==0)
	return 1.0;

	ld W=(ld)w, B=(ld)b;

	ans+=(ld)W/(W+B);

	if (who==0)
		ans+=(ld)B/(W+B)*(1.0-cnt(w, b-1, 1));
	else
	ans+=(ld)B/(W+B)* ( (ld)(B-1)/(B+W-1)*(1.0-cnt(w, b-2, 0)) + (ld) W/(B+W-1)*( 1.0-cnt(w-1, b-1, 0) ) );

	//cout<<w<<' '<<b<<endl;
	//printf ("%.10lf\n", (double)ans);

	return dp[w][b]=ans;

}

void solve()
{
	int w, b;
	cin>>w>>b;
	ww=w; bb=b;
	for (int i=0; i<=1000; i++)
		for (int j=0; j<=1000; j++)
			dp[i][j]=-1.0;
	ld ans=cnt(w, b, 0);
	printf ("%.10lf", (double)ans);
}