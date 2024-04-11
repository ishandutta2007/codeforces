#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;

void solve ();

int main ()
{
#ifdef _DEBUG
	freopen ("in.txt","r",stdin);
#endif
	solve ();
	return 0;
}
//#define int li
string s;
void solve()
{
	cin>>s;
	string q;
	bool f=false;
	for ( int i=0; i<s.length(); i++ )
		if ( s[i]!='/' )
		{
			q.pb(s[i]);
			f=true;
		}
		else 
		{
			q.pb('/');
			while ( i<s.length() && s[i]=='/' )
				i++;
			if (i==s.length() && f)
				q.resize(q.size()-1);
			else 
				i--;
		}
	cout<<q;
}