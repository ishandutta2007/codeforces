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
    ios_base::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

//#define int li

int n, x;
int a[1000];

void solve()
{  
    cin>>n>>x;
    bool f=false;
    int ans=0;
    for (int i=0; i<n; i++)
    {
        cin>>a[i];
        if (a[i]==x)
            f=true;
    }
    if (!f)
        a[n]=x, n++, ans++;
    sort (a, a+n);
    int l=-1, r=-1;
    for (int i=0; i<n; i++)
        if (a[i]==x)
        {
            l=i;
            r=i;
            while (r<n && a[r]==x)
                r++;
            r--;
            break;
        }
    int k=(n-1)/2;
    if (l<=k && k<=r)
    {
        cout<<ans;
        return;
    }
    if (l>k)
    {
        ans+=2*l+1-n;
        cout<<ans;
        return;
    }
    if (k>r)
    {
        ans+=n-2*r-2;
        cout<<ans;
        return;
    }
}