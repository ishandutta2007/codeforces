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

#define int li

int n, m;
pair <int, int> a[100500];
int k;
pair <int, int> cur;

bool good (pair <int, int> q)
{
	return q.first>=0 && q.first<n && q.second>=0 && q.second<m;
}

void solve()
{
	cin>>n>>m;
	cin>>cur.first>>cur.second;
	cur.first--; cur.second--;
	cin>>k;
	for (int i=0; i<k; i++)
		cin>>a[i].first>>a[i].second;
	int ans=0;
	for (int i=0; i<k; i++)
	{
		int l=0, r=5000000000;
		while (l+1<r)
		{
			int mm=l+r; mm/=2;
			if (good( mp ( cur.first + mm*a[i].first, cur.second + mm*a[i].second ) ))
				l=mm;
			else
				r=mm;
		}
		cur.first+=l*a[i].first;
		cur.second+=l*a[i].second;
		ans+=l;
	}
	cout<<ans;

}