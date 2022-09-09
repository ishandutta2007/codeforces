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
#define all(a) a.begin(), a.end()

typedef long long li;
typedef double ld;
typedef vector <int> vi;
typedef pair <int, int> pi;
typedef vector <li> vli;
typedef pair <li, li> pli;

void solve();
int main() 
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while (t--)
        solve();
    return 0;

}

#define int li

int k, n;
int b;
int a[100500];
pair <int, int> c[100500];
int pref[100500];

int sum (int l, int r)
{
    if (l>r)
        return 0;
    return pref[r]-( (l>0)?pref[l-1]:0 );
}

int bp (pair <int, int> val)
{
    int l=0, r=n;
    while (l+1<r)
    {
        int m=l+r; m>>=1;
        if (c[m]<val)
            r=m;
        else
            l=m;
    }
    return l;
}

void solve()
{  
    cin>>n>>k>>b;
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
        c[i].first=a[i], c[i].second=i;
    }
    sort (c, c+n-1);
    reverse (c, c+n-1);
    pref[0]=c[0].first;
    for (int i=1; i<n; i++)
        pref[i]=pref[i-1]+c[i].first;
    k--;
    for (int i=0; i<n-1; i++)
    {
        int cur=bp( mp(a[i], i) );
        if (cur>=k)
        {
            if (sum(0, k-1)+a[i]>b)
            {
                cout<<i+1;
                return;
            }
        }
        else
        {
            if (sum(0, k)>b)
            {
                cout<<i+1;
                return;
            }
        }
    }
    cout<<n;
}