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
#define FILE "roads"
int main ()
{
#ifdef DEBUG
	freopen ("in.txt", "r", stdin);
	//freopen ("out.txt", "w", stdout);
	cout<<FILE<<endl;
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

int n, m, k;

vector < pair <int, int> > fre, pay;

struct dsu
{
	int a[100500];
	dsu() {}
	void build()
	{
		for (int i=0; i<n; i++)
		a[i]=i;
	}
	int find_set (int v)
	{
		if (a[v]==v)
		return v;
		return a[v]=find_set(a[v]);
	}
	void merge (int q, int w)
	{
		q=find_set(q);
		w=find_set(w);
		if (rand() & 1)
		a[q]=w;
		else
		a[w]=q;
	}
};

dsu a, b;

vector <int> nums1, nums2;

vector <int> ans;

void solve()
{
	cin>>n>>m;
	if (n%2==0)
	{
		cout<<"-1";
		return;
	}
	k=(n-1)/2;
	a.build();
	b.build();
	for (int i=0; i<m; i++)
	{
		int q, w; char r;
		cin>>q>>w>>r;
		q--; w--;
		if (r=='S')
		fre.pb(mp(q, w)), nums1.pb(i);
		else
		pay.pb(mp(q, w)), nums2.pb(i);
	}
	for (int i=0; i<fre.size(); i++)
	{
		pi cur=fre[i];
		if (a.find_set(cur.first)!=a.find_set(cur.second))
			a.merge(cur.first, cur.second);
	}
	vector <int> now;
	for (int i=0; i<n; i++)
	now.pb(a.find_set(i));
	sort (now.begin(), now.end());
	now.resize( unique (now.begin(), now.end()) - now.begin() );
	if (now.size() > k+1)
	{
		cout<<"-1";
		return;
	}
	int num=0;
	for (int i=0; i<pay.size(); i++)
	{
		pi cur=pay[i];
		if (a.find_set(cur.first)!=a.find_set(cur.second))
		{
			a.merge(cur.first, cur.second);
			b.merge(cur.first, cur.second);
			ans.pb(nums2[i]);
			num++;
		}
	}
	if ((num+1)!=now.size())
	{
		cout<<"-1";
		return;
	}

	for (int i=0; i<pay.size() && num<k; i++)
	{
		pi cur=pay[i];
		//cout<<b.find_set(cur.first)<<' '<<b.find_set(cur.second)<<endl;
		if (b.find_set(cur.first)!=b.find_set(cur.second))
		{
			b.merge (cur.first, cur.second);
			ans.pb(nums2[i]);
			num++;
		}
	}
	if (num!=k)
	{
		cout<<"-1";
		return;
	}

	for (int i=0; i<fre.size(); i++)
	{
		pi cur=fre[i];
		if (b.find_set(cur.first)!=b.find_set(cur.second))
		{
			b.merge(cur.first, cur.second);
			ans.pb(nums1[i]);
		}
	}

	cout<<ans.size()<<endl;
	for (int i=0; i<ans.size(); i++)
	cout<<ans[i]+1<<' ';
}