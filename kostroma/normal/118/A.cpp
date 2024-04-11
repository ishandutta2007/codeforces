#define CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <stdlib.h>
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
string s;
void solve ()
{
	cin>>s;
	for (int i=0; i<s.length(); i++)
		if (s[i]<'a')
			s[i]+='a'-'A';
	string q;
	for (int i=0; i<s.length(); i++)
		if ( s[i]!='a' && s[i]!='o' && s[i]!='y' && s[i]!='e' && s[i]!='u' && s[i]!='i' )
			q.pb(s[i]);
	for (int i=0; i<q.length(); i++)
		cout<<'.'<<q[i];
}