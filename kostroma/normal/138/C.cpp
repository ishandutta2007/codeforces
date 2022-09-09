#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) (a.begin(), a.end())

typedef long long li;
typedef long double ld;

void solve ();

int main ()
{
#ifdef DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
		solve();
	return 0;
}
//#define int li
int n, m;
struct tree
{
	int a, h;
	ld l, r;
	void scan () { scanf ("%d%d", &a, &h); cin>>l>>r; }

};
tree a[100500];
pair <int, int> b[10050];
int bp (int val)
{
	int ll=-1, rr=m-1;
	while (ll+1<rr)
	{
		int mm=ll+rr; mm/=2;
		if ( b[mm].first>=val )
			rr=mm;
		else
			ll=mm;
	}
	if (b[rr].first<val)
		rr++;
	return rr;
}
ld mult[10050];
void solve ()
{
	cin>>n>>m;
	for (int i=0; i<n; i++)
		a[i].scan();
	for (int i=0; i<m; i++)
		cin>>b[i].first>>b[i].second;
	sort (b, b+m);
	for (int i=0; i<=m; i++)
		mult[i]=1.0;
	for (int i=0; i<n; i++)
	{
		int ind1=bp (a[i].a-a[i].h);
		int ind2=bp (a[i].a);
		mult[ind1]*=((100.0-a[i].l+1e-20)/100.0);
		mult[ind2]/=((100.0-a[i].l+1e-20)/100.0);
	}
	for (int i=0; i<n; i++)
	{
		int ind1=bp (a[i].a+1);
		int ind2=bp (a[i].a+a[i].h+1);
		mult[ind1]*=((100.0-a[i].r+1e-20)/100.0);
		mult[ind2]/=((100.0-a[i].r+1e-20)/100.0);
	}
	ld ans=0.0;
	ld dom=1.0;
	for (int i=0; i<m; i++)
	{
		dom*=mult[i];
		ld g=b[i].second;
		ans+=g*dom;
	}
	dom*=mult[m];
	printf ("%.10lf", (double)ans);
}