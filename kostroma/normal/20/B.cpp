#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>
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
#define int li
int a, b, c;
void solve()
{
	cin>>a>>b>>c;
	if (a<0)
	{
		a=-a; b=-b; c=-c;
	}
	if (a==0)
	{
		if ( b==0 )
		{
			if (c==0)
				cout<<"-1";
			else 
				cout<<"0";
			return;
		}
		cout<<"1\n";
		ld z=(ld)-c;
		z/=(ld)b;
		printf ("%.10Lf", z);
		return;
	}
	int d=b*b-4*a*c;
	if (d<0)
	{
		cout<<"0";
		return;
	}
	if (d==0)
	{
		cout<<"1\n";
		ld z=(ld)-b;
		ld znam=(ld)a*2.00;
		z/=znam;
		printf ("%.10Lf", z);
		return;
	}
	ld D=(ld)sqrt((ld)d);
	cout<<"2\n";
	ld znam=(ld)2.00*a;
	ld z1=(ld)-b, z2=(ld)-b; z1-=D; z2+=D;
	z1/=znam; z2/=znam;
	printf ("%.10Lf\n%.10Lf", z1, z2);
}