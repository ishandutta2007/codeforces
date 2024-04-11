#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <math.h>
#include <queue>
#include <memory.h>

using namespace std;

/*
CAUTION: IS INT REALLY INT, BUT NOT LONG LONG?
REAL SOLTION AFTER MAIN FUNCTION
*/

#define mp make_pair
#define pb push_back

typedef long long li;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef vector <li> vli;
typedef pair <li, li> pli;

void solve();
int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    //ios_base::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

#define int li
double eps=1e-11;
int n, k;
double h;
pair < pair <double, double>, int > a[1000500];


bool bad (double val)
{
    int u=1;
    for (int i=0; i<n; i++)
    {
        double hh=(double)u;
        if ( hh*h<a[i].first.second*val + eps )
            u++;
    }

    //cout<<val<<' '<<u<<endl;

    if (u>k)
        return false;
    return true;
}

void solve()
{
    cin>>n>>k>>h;
    for (int i=0; i<n; i++)
        cin>>a[i].first.first, a[i].second=i;
    for (int i=0; i<n; i++)
        cin>>a[i].first.second;
    sort (a, a+n);
    double l=0.0, r=1000000007.0;
    for (int i=0; i<200; i++)
    {
        double mm=l+r; mm/=2.0;
        if (bad(mm))
            l=mm;
        else
            r=mm;
    }

    //cout<<r<<endl;

    vector <int> ans;
    int u=1;
    for (int i=0; i<n; i++)
    {
        double hh=(double)u;
        if ( hh*h<a[i].first.second*r + eps )
            u++, ans.pb(a[i].second);
    }

    for (int i=0; i<k; i++)
        cout<<ans[i]+1<<' ';

}