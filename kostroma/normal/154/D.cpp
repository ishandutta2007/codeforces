#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <map>
using namespace std;
/*
BE CAREFUL: ISN'T INT EQUAL TO LONG LONG?

REAL SOLUTION AFTER MAIN FUNCTION
*/
#define mp make_pair
#define pb push_back
typedef long long li;
typedef long double ld;
typedef pair <int, int> pi;
void solve();

int main ()
{
       
#ifdef _DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int t=1;
    while (t--)
                solve();
    return 0;
}

#define int li

int x1, x2, a, b;

void solve ()
{
	  bool f=false;
      cin>>x1>>x2>>a>>b;
	  if (x1>x2)
	  {
		  f=true;
		  swap(a, b);
		  a=-a;
		  b=-b;
		  swap (x1, x2);
	  }
	  if ( x2<=b+x1 && x2>=a+x1 )
	  {
		  if (!f)
		  cout<<"FIRST"<<endl<<x2;
		  else	
			cout<<"FIRST"<<endl<<x1;
		  return;
	  }
	  if (a<=0 && b>=0)
	  {
		  cout<<"DRAW";
		  return;
	  }
	  if (b<0)
	  {
		  cout<<"DRAW";
		  return;
	  }
	  if (( x2-x1 )%(a+b)==0)
	  {
		  cout<<"SECOND";
		  return;
	  }
	  int cur=x2-x1;
	  int now=cur/(a+b);
	  if ( cur>=a+now*(a+b) && cur<=b+now*(a+b) )
	  {
		  cout<<"FIRST\n";
		  if (!f)
		  cout<<x2-now*(a+b);
		  else
			cout<<x1+now*(a+b);
		  return;
	  }
	  cout<<"DRAW";

}