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

//#define int li

int n, m;
double c;
double x[200500], p[200500];
double pref[200500];

const int shift=1<<19;

pair <double, pair <double, double> > tree[2*shift+6];

double sums[2*shift+6];

pair <pair <double, pair <double, double> >, double> sum (int l, int r)
{
	if (l>r)
		return mp ( mp ( 0.0, mp(0.0, 0.0) ), 0.0 );
	if (l%2)
	{
		pair <pair <double, pair <double, double> >, double > now=sum(l+1, r);
		pair <double, pair <double, double> > cur=now.first;
		pair <double, pair <double, double> > ans;

		ans.first=max( cur.first, tree[l].first );
		ans.first=max( ans.first, tree[l].second.second + cur.second.first );

		ans.second.first=max( tree[l].second.first, sums[l]+cur.second.first );

		ans.second.second=max( cur.second.second, now.second + tree[l].second.second );

		return mp ( ans, sums[l]+now.second );
	}
	if (r%2==0)
	{
		pair <pair <double, pair <double, double> >, double > now=sum(l, r-1);
		pair <double, pair <double, double> > cur=now.first;
		pair <double, pair <double, double> > ans;

		ans.first=max( cur.first, tree[r].first );
		ans.first=max( ans.first, tree[r].second.first + cur.second.second );

		ans.second.first=max( cur.second.first, now.second + tree[r].second.first );

		ans.second.second=max( tree[r].second.second, sums[r] + cur.second.second );

		return mp ( ans, sums[r]+now.second );
	}
	return sum (l/2, r/2);
}

void solve()
{
	cin>>n>>m>>c;
	for (int i=0; i<n; i++)
		scanf ("%lf", &x[i]);
	for (int i=0; i<n-1; i++)
		scanf ("%lf", &p[i]), p[i]/=100.0;
	pref[0]=p[0];
	for (int i=1; i<n-1; i++)
		pref[i]=pref[i-1]+p[i];

	for (int i=0; i<2*shift+6; i++)
		tree[i]=mp ( 0.0, mp(0.0, 0.0) ), sums[i]=0.0;

	for (int i=0; i<n-1; i++)
	{
		double cur=(x[i+1]-x[i])/2.0;
		cur-=p[i]*c;
		if (cur>0.0)
			tree[shift+i].first=tree[shift+i].second.first=tree[shift+i].second.second=cur;
		sums[i+shift]=cur;
	}

	//for (int i=shift; i<shift+n-1; i++)
	//	printf ("%.10lf\n", tree[i].first);

	for (int i=shift-1; i>=0; i--)
		sums[i]=sums[2*i]+sums[2*i+1];

	for (int i=shift-1; i>=0; i--)
	{
		tree[i].first=max( tree[2*i].first, tree[2*i+1].first );
		tree[i].first=max( tree[i].first, tree[2*i].second.second + tree[2*i+1].second.first );

		tree[i].second.first=max(tree[2*i+1].second.first + sums[2*i], tree[2*i].second.first);

		tree[i].second.second=max(tree[2*i].second.second + sums[2*i+1], tree[2*i+1].second.second);
	}


	double ans=0.0;

	for (int i=0; i<m; i++)
	{
		int a, b;
		scanf ("%d%d", &a, &b);
		a--; b--;
		//cout<<a<<' '<<b-1<<endl;
		pair <pair <double, pair <double, double> >, double> now=sum(a+shift, b-1+shift);
		ans+=now.first.first;
		//printf ("%.10lf\n", now.first.first);
	}

	printf ("%.10lf", ans);

}