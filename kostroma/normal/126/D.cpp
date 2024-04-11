#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <vector>
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
//#else 
//      freopen ("input.txt", "r", stdin);
//      freopen ("output.txt", "w", stdout);
#endif
    int t=1;
	cin>>t;
    while (t--)
    solve();
    return 0;
}
#define int li
int n;
vector <int> fib;
vector <int> one;
vector <int> dp1, dp2;
void solve ()
{
     cin>>n;
	 if ( n<3 )
	 {
		 cout<<"1\n";
		 return;
	 }
	 fib.resize(0);
	 dp1.resize(0);
	 dp2.resize(0);
	 one.resize(0);
	 fib.pb(1);
	 fib.pb(2);
	 while ( fib[fib.size()-1]+fib[fib.size()-2]<=n )
		 fib.pb (fib[fib.size()-1]+fib[fib.size()-2]);
	 int m=n;
	 for ( int i=fib.size()-1; i>=0 && m>0; i-- )
		 if ( m>=fib[i] )
		 {
			 one.pb(i);
			 m-=fib[i];
		 }
	one.pb(-1);
	sort (one.begin(), one.end());

	

	dp1.resize(one.size()+1);
	dp2.resize(one.size()+1);
	dp1[0]=1; dp2[0]=0;
	for ( int i=0; i<one.size()-1; i++ )
	{
		dp1[i+1]=dp1[i]+dp2[i];
		dp2[i+1]=dp1[i]*( (one[i+1]-one[i]-1)/2 )+dp2[i]*( (one[i+1]-one[i])/2 );
	}
	cout<<dp1[one.size()-1]+dp2[one.size()-1]<<endl;
}