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

int n, k;
pair <int, int> a[100500];

void solve()
{  
    cin>>n>>k;
    for (int i=0; i<n; i++)
        cin>>a[i].first>>a[i].second, a[i].second=-a[i].second;
    sort (a, a+n);
    reverse(a, a+n);
    int ans=0;
    pair <int, int> cur=a[k-1];
    for (int i=0; i<n; i++)
        if (a[i]==cur)
            ans++;
    cout<<ans;
}