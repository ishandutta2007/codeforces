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

string s;
int k;
string bad[20];
vector <pair <char, int> > a;
bool bb (char q, char w)
{
	for (int i=0; i<k; i++)
		if ( (bad[i][0]==q && bad[i][1]==w ) || (bad[i][0]==w && bad[i][1]==q ) )
			return true;
	return false;
}

void solve()
{
	cin>>s;
	cin>>k;
	for (int i=0; i<k; i++)
		cin>>bad[i];
	for (int i=0; i<s.length(); i++)
	{
		int j=i+1;
		while (j<s.length() && s[j]==s[i])
			j++;
		a.pb(mp( s[i], j-i ));
		i=j-1;
		if (j==s.length())
			break;
	}
	int ans=0;
	for (int i=0; i<a.size(); i++)
	{
		int j=i+1;
		int one=a[i].second, two=0;
		while (j<a.size() && bb ( a[j-1].first, a[j].first ) )
		{
			if ( (j-i)%2 )
				two+=a[j].second;
			else
				one+=a[j].second;
			j++;
		}
		ans+=min(one, two);
		i=j-1;
		if (j==a.size())
			break;
	}
	cout<<ans;
}