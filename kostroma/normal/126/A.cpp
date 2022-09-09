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
        while (t--)
    solve();
    return 0;
}
#define int li
int x1, x2, t1, t2, t0;
void solve ()
{
        cin>>t1>>t2>>x1>>x2>>t0;
        if (t1==t0)
        {
                if (t2==t0)
                {
                        cout<<x1<<' '<<x2;
                        return;
                }
                else 
                {
                        cout<<x1<<' '<<"0";
                        return;
                }
        }
        if (t0==t2)
        {
                cout<<0<<' '<<x2;
                return;
        }
        int ans=1LL<<60;
        pi answer=mp(-1, -1);
        for ( int y2=0; y2<=x2; y2++ )
        {
                int z=y2*(t2-t0);
                int y1=z/(t0-t1);
                if (y1>x1)
                        y1=x1;
				if (y1==0 && y2==0)
					continue;
                if ( ans==1LL<<60 || (y1*(t1-t0)+y2*(t2-t0))*(answer.first+answer.second)<ans*(y1+y2) )
                {
                        ans=y1*(t1-t0)+y2*(t2-t0);
                        answer=mp (y1, y2);
                }
                else
                        if ( (y1*(t1-t0)+y2*(t2-t0))*(answer.first+answer.second)==ans*(y1+y2) && answer.first+answer.second<y1+y2)
                                {
										ans=(y1*(t1-t0)+y2*(t2-t0));
                                        answer=mp (y1, y2);
                                }
        }
        cout<<answer.first<<' '<<answer.second;
}