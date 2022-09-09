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
string s[200];
int mod=1000000007;
void solve()
{
	cin>>n>>m;
	for (int i=0; i<n; i++)
		cin>>s[i];
	int ans=1;
	for (int j=0; j<m; j++)
	{
		set <char> a;
		for (int i=0; i<n; i++)
			a.insert(s[i][j]);
		int cur=a.size();
		ans*=cur; ans%=mod;
	}
	cout<<ans;
}