#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>
#include <set>
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
void solve()
{
	int a1, b1, c1, a2, b2, c2;
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	if ( a1==0 && b1==0 )
	{
		if (c1!=0)
		{
			cout<<"0";
			return;
		}
		else 
		{
			if ( a2!=0 || b2!=0 )
				cout<<"-1";
			else 
				if (c2==0)
					cout<<"-1";
				else 
					cout<<"0";
		}
		return;
	}
	if ( a2==0 && b2==0 )
	{
		if (c2!=0)
		{
			cout<<"0";
			return;
		}
		else 
		{
			if ( a1!=0 || b1!=0 )
				cout<<"-1";
			else 
				if (c1==0)
					cout<<"-1";
				else 
					cout<<"0";
		}
		return;
	}
	if ( a1*b2==a2*b1 )
	{
		if (a1*c2==a2*c1)
			cout<<"-1";
		else 
			cout<<"0";
	}
	else 
		cout<<"1";
}