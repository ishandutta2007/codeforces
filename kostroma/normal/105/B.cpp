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
int n, k, A;
int b[10], l[10];
ld ans=0;
void conf ( vector <int> lcur, int rest )
{
        if (lcur.size()==n-1)
        {
                if (rest>10-l[n-1])
                        return;
                lcur.pb(rest+l[n-1]);
                conf(lcur, 0);
                return;
        }
        if (lcur.size()==n)
        {
                ld p=0;
                for ( int mask=0; mask<(1<<n); mask++ )
                {
                        int how=0;
                        for ( int j=0; j<n; j++ )
                                if ( mask & (1<<j) )
                                        how++;
                        int nowp=1;
                        for ( int j=0; j<n; j++ )
                                if ( mask & (1<<j) )
                                        nowp*=lcur[j];
                                else 
                                        nowp*=(10-lcur[j]);
                        if (how>n/2)
                        {
                        //cout<<lcur[0]<<endl;
                        p+=(ld)nowp;
                        }
                        else 
                        {
                                int sum=0;
                                for (int j=0; j<n; j++)
                                        if ( !( mask & (1<<j) ) )
                                                sum+=b[j];
                                ld dob=(ld)A/(A+sum);
                                dob*=(ld)nowp;
                                p+=dob;
                        }
                }
                ans=max(ans, p);
                return;
        }
        for (int i=0; i<=rest && l[lcur.size()]+i<=10; i++)
        {
                lcur.pb(l[lcur.size()]+i);
                conf (lcur, rest-i);
                lcur.pop_back();
        }
}
void solve ()
{
        cin>>n>>k>>A;
        for (int i=0; i<n; i++)
        {
                int q;
                cin>>b[i]>>q;
                l[i]=q/10;
        }
	int summ=0;
	for ( int i=0; i<n; i++ )
		summ+=10-l[i];
	if (summ<=k)
{
	printf ("1.000000000000000");
	return;
}
        conf ( vi(), k );
        int del=1;
        for (int i=0; i<n; i++)
                del*=10;
        ld answer=(ld)ans/del;
        printf ("%.9Lf", answer);
}