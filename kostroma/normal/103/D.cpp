#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <string.h>
#include <memory.h>
#include <algorithm>
#include <math.h>
using namespace std;

typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
typedef pair <li, li> pli;
typedef vector <int> vi;
typedef vector <li> vli;
#define mp make_pair
#define pb push_back
void solve ();
int main ()
{
#ifdef _DEBUG
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
		solve ();
	return 0;
}
//caution: is int really int?
//#define int li
struct question 
{
	int a, b, id;
	question() {};
	question ( int A, int B, int Id ) { a=A; b=B; id=Id; }
	bool operator < ( question &w ) { return b<w.b || (b==w.b && (a%b)<(w.a%b)); }
};
int n, p, a[300500];
question Q[300500];
li pref[300500];
li ans[300500];
void solve ()
{
	scanf ("%d", &n);
	for (int i=0; i<n; i++)
		scanf ("%d", &a[i]);
	scanf ("%d", &p);
	int t=0;
	for ( int i=0; i<p; i++ )
	{
		int q, w;
		scanf ("%d%d", &q, &w);
		Q[t++]=question(q-1, w, i);
	}
	sort (Q, Q+p);
	for ( int i=0; i<p; i++ )
	{
		pi cur=mp( Q[i].a, Q[i].b );
		int now=cur.first%cur.second;
		pref[now]=(li)a[now];
		for ( int j=now+cur.second; j<n; j+=cur.second )
			pref[j]=(li)pref[j-cur.second]+a[j];
		int end=((n-1-now)/cur.second)*cur.second+now;
		bool flag=true;
		while ( i<p && Q[i].b==cur.second && Q[i].a%cur.second==now )
		{
			if ( Q[i].a==now )
				ans[Q[i].id]=pref[end];
			else 
				ans[Q[i].id]=pref[end]-pref[Q[i].a-cur.second];
			i++;
			if ( i==p )
			{
				flag=false;
				break;
			}
		}
		if (flag)
		i--;
	}
	for ( int i=0; i<p; i++ )
		printf ("%I64d\n", ans[i]);
}