#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:32000000")
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
int n, k, q, num;
int a[200];
bool used[200];
int mn=1<<30, mx=0;
set <vector <int> > ss;
void solve ()
{
        cin>>n>>k;
        num=n/k;
        for (int i=1; i<=n; i++)
                cin>>a[i];
        cin>>q;
        for (int i=0; i<q; i++)
        {
                int curans=0;
				vector <int> now;
                for (int j=0; j<num; j++)
                {
                        int cur;
                        cin>>cur;
						now.pb(cur);
                        used[cur]=true;
                        curans+=a[cur];
                }
				sort (now.begin(), now.end());
				ss.insert(now);
                mn=min (mn, curans);
                mx=max (mx, curans);
        }
        vector <int> unused;
        for (int i=1; i<=n; i++)
                if ( !used[i] )
                        unused.pb (a[i]);
        sort (unused.begin(), unused.end());
        if (unused.size()>=num && ss.size()<k)
        {
                int z=0;
                for (int i=0; i<num; i++)
                        z+=unused[i];
                mn=min (mn, z);
                z=0;
                for ( int i=(int)unused.size()-1; i>(int)unused.size()-1-num; i--)
                        z+=unused[i];
                mx=max (mx, z);
        }
        ld mnans=(ld)mn/num, mxans=(ld)mx/num;
        printf ("%.10Lf %.10Lf", mnans, mxans);
}