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

int n, m;
vector <int> a[200];
vector <int> pref[200];

int sums[200][200];

int sum (int i, int l, int r)
{
	if (l>r)
	return 0;
	return pref[i][r]-( (l==0)?0:pref[i][l-1] );
}

int dp[10050];

void solve()
{
	cin>>n>>m;
	memset (sums, -1, sizeof sums);
	for (int i=0; i<n; i++)
	{
		int q;
		cin>>q;
		while (q--)
		{
			int w;
			cin>>w;
			a[i].pb(w);
		}

		pref[i].pb(a[i][0]);
		for (int j=1; j<a[i].size(); j++)
			pref[i].pb( pref[i][j-1]+a[i][j] );

		for (int j=0; j<=a[i].size(); j++)
		{
			for (int k=0; k<=j; k++)
			{
				int r=j-k;
				if (r>a[i].size())
				continue;
				int cur=sum(i, 0, k-1)+sum(i, a[i].size()-r, a[i].size()-1);
				sums[i][j]=max(sums[i][j], cur);
			}
		}
	}

	memset (dp, -1, sizeof dp);
	dp[0]=0;
	for (int i=0; i<n; i++)
	{
		for ( int j=m; j>=0; j-- )
			for (int k=0; k<=a[i].size(); k++)
			{
				if ( sums[i][k]!=-1 && j-k>=0 && (dp[j]==-1 || dp[j]<dp[j-k]+sums[i][k] ))
					dp[j]=sums[i][k]+dp[j-k];
			}
	}
	cout<<dp[m];

}