#include<iostream>
#include<cstdio>
#include<string>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
typedef long long li;
typedef pair <int, int> pi;
#define mp make_pair
#define pb push_back
void solve ();
int main()
{
		freopen("input.txt","r",stdin);
#ifndef _DEBUG
	freopen("output.txt","w",stdout);
#endif
	 solve();
	return 0;
}
//#define int li
const int MAXN=100500;
struct pt {
	int x, y, id;
	pt () { x=0; y=0; id=0; }
	pt (int X, int Y, int Id) { x=X; y=Y; id=Id; }
};
 
inline bool cmp_x (const pt & a, const pt & b) {
	return a.x < b.x || a.x == b.x && a.y < b.y;
}
 
inline bool cmp_y (const pt & a, const pt & b) {
	return a.y < b.y;
}
int n;
pt a[MAXN];
double mindist;
int ansa, ansb;
int z[MAXN];
inline void upd_ans (const pt & a, const pt & b) {
	double dist = sqrt ((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) + .0);
	if (dist < mindist)
		mindist = dist,  ansa = a.id,  ansb = b.id;
}
void rec (int l, int r) {
	if (r - l <= 3) {
		for (int i=l; i<=r; ++i)
			for (int j=i+1; j<=r; ++j)
				upd_ans (a[i], a[j]);
		sort (a+l, a+r+1, &cmp_y);
		return;
	}
 
	int m = (l + r) >> 1;
	int midx = a[m].x;
	rec (l, m),  rec (m+1, r);
	inplace_merge (a+l, a+m+1, a+r+1, &cmp_y);
 
	static pt t[MAXN];
	int tsz = 0;
	for (int i=l; i<=r; ++i)
		if (abs (a[i].x - midx) < mindist) {
			for (int j=tsz-1; j>=0 && a[i].y - t[j].y < mindist; --j)
				upd_ans (a[i], t[j]);
			t[tsz++] = a[i];
		}
}
pi points[MAXN];
void solve()
{
	cin>>n;
	for ( int i=0; i<n; i++ )
	{
		int q, w;
		cin>>q>>w;
		points[i]=mp (q, w);
		if ( q>=0 && w>=0 )
		{
			z[i]=1;
			a[i]=pt(q, w, i);
			continue;
		}
		if ( q>=0 && w<0 )
		{
			z[i]=3;
			a[i]=pt ( q, -w, i );
			continue;
		}
		if ( q<0 && w>=0 )
		{
			z[i]=2;
			a[i]=pt ( -q, w, i );
			continue;
		}
		z[i]=4;
		a[i]=pt ( -q, -w, i );
	}
	sort (a, a+n, &cmp_x);
	mindist = 1E20;
	rec (0, n-1);
	cout<<ansa+1<<' '<<z[ansa]<<' '<<ansb+1<<' '<<5-z[ansb];
}