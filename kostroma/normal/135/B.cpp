#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;

void solve();

int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
		solve();
	return 0;
}

//#define int li
struct pt
{
	int x, y;
	pt () {}
	pt (int X, int Y) { x=X; y=Y; }
	int operator ^ (pt b) { return x*b.x+y*b.y; }
	int operator * (pt b) { return x*b.y-y*b.x; }
	pt operator - (pt b) { return pt (x-b.x, y-b.y); }
	void scan () { cin>>x>>y; }
	int dist () { return x*x+y*y; }
};

pt a[8];

bool is_pryam (pt q, pt w, pt r, pt t)
{
	if ( (q-w)*(r-t)!=0 )
		swap (q, r);
	if ( (q-w)*(r-t)!=0 )
		return false;
	if ( (q-t)*(w-r)!=0 )
		swap (r, t);
	if ( (q-t)*(w-r)!=0 )
		return false;

	return ((q-w)^(q-t))==0;
}
bool is_kvadr (pt q, pt w, pt r, pt t)
{
	if ( (q-w)*(r-t)!=0 )
		swap (q, r);
	if ( (q-t)*(w-r)!=0 )
		swap (r, t);
	return (q-t).dist()==(q-w).dist();
}
int p[8];

void solve()
{
	for (int i=0; i<8; i++)
		a[i].scan();
	p[4]=p[5]=p[6]=p[7]=1;
	do
	{
		vector <int> a1, a2;
		for (int i=0; i<8; i++)
			if (p[i])
				a1.pb(i);
			else 
				a2.pb(i);

		if ( !is_pryam(a[a1[0]], a[a1[1]], a[a1[2]], a[a1[3]]) || !is_pryam(a[a2[0]], a[a2[1]], a[a2[2]], a[a2[3]]))
			continue;
		if ( is_kvadr(a[a1[0]], a[a1[1]], a[a1[2]], a[a1[3]]) )
		{
			cout<<"YES\n";
			cout<<a1[0]+1<<' '<<a1[1]+1<<' '<<a1[2]+1<<' '<<a1[3]+1<<endl;
			cout<<a2[0]+1<<' '<<a2[1]+1<<' '<<a2[2]+1<<' '<<a2[3]+1;
			return;
		}
	}
	while (next_permutation (p, p+8) );

	cout<<"NO";
}