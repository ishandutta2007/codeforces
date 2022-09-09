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
int n, k;
string s;
map <char, int> m;
typedef map<char, int>::iterator it;
void solve ()
{
	cin>>s;
	n=s.length();
	cin>>k;
	for ( int i=0; i<n; i++ )
		m[s[i]]++;
	while (k>0)
	{
		char c; int mn=1<<30;
		for ( it i=m.begin(); i!=m.end(); i++ )
		{
			if ( i->second<mn )
			{
				mn=i->second; c=i->first;
			}
		}
		if ( k>=mn )
		{
			k-=mn;
			m.erase(c);
		}
		else 
			break;
	}
	cout<<m.size()<<endl;
	for ( int i=0; i<n; i++ )
		if ( m.find(s[i])!=m.end() )
			cout<<s[i];
}