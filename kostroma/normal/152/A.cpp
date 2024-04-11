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
int a[200][200];
int mx[200];
void solve()
{
	cin>>n>>m;
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			scanf ("%1d", &a[i][j]);
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
			if (mx[j]<a[i][j])
				mx[j]=a[i][j];
	}
	int ans=0;
	for (int i=0; i<n; i++)
	{
		bool f=false;
		for (int j=0; j<m; j++)
			if (a[i][j]==mx[j])
				f=true;
		if (f)
			ans++;
	}
	cout<<ans;

}