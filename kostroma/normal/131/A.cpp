#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <memory.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair <int, int> pi;
typedef long double ld;
typedef long long li;
void solve();
int main ()
{
#ifndef ONLINE_JUDGE
	freopen ("in.txt", "r", stdin);
#endif
	int t=1;
	while (t--)
	solve();
	return 0;
}
//#define int li
string s;
void solve()
{
     cin>>s;
     if (s[0]>='a' && s[0]<='z')
     {
          bool f=true;
          for (int i=1; i<s.length(); i++)
          if (s[i]>='a' && s[i]<='z')
          {
               f=false;
               break;
          }
          if (f)
          {
               s[0]+='A'-'a';
               for (int i=1; i<s.length(); i++)
               s[i]+='a'-'A';
          }
          cout<<s;
          return;
     }
     bool f=true;
     for (int i=0; i<s.length(); i++)
     if ( s[i]>='a' && s[i]<='z' )
     {
          f=false;
          break;
     }
     if (f)
     for (int i=0; i<s.length(); i++)
     s[i]+='a'-'A';
     cout<<s;
}