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
string t, s1, s2;
vector <int> pos1, pos2;
bool good (int p, string z)
{
	if ( (int)t.length()-p<z.length() )
		return false;
	for (int i=0; i<z.length(); i++)
		if (z[i]!=t[i+p])
			return false;
	return true;
}
vector <li> hashes;
void solve ()
{
     cin>>t>>s1>>s2;
	 for ( int i=0; i<t.length(); i++ )
	 {
		 if ( good(i, s1) )
			 pos1.pb (i);
		 if (good(i, s2))
			 pos2.pb(i);
	 }
	 for ( int i=0; i<pos1.size(); i++ )
	 {
		 li has=0, z=pos1[i];
		 for (int j=0; j<pos2.size(); j++)
			 if ( pos1[i]<=pos2[j] && pos1[i]+s1.length()<=pos2[j]+s2.length() )
			 {
				 for ( int k=z; k<pos2[j]+s2.length(); k++ )
					 has=has*29LL+t[k];
				 z=pos2[j]+s2.length();
				 hashes.pb (has);
			 }
	 }
	//cout<<hashes.size()<<endl;
	sort (hashes.begin(), hashes.end());
	hashes.resize(unique(hashes.begin(), hashes.end())-hashes.begin());
	cout<<hashes.size();
}