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

int n, u, r;
int a[100], b[100], k[100], p[100];
int answer=-(1LL<<60);
void rec (int last=0, int done=0)
{
    int curans=0;
    for (int i=0; i<n; i++)
        curans+=a[i]*k[i];
    if ( (u-done)%2==0 )
        answer=max(answer, curans);
    if (done>=u)
        return;
    int aa[100];
    for (int i=0; i<n; i++)
        aa[i]=a[i];
    if (last==0)
    {
        for (int i=0; i<n; i++)
            a[i]=a[i]^b[i];
        rec (1, done+1);
        for (int i=0; i<n; i++)
            a[i]=aa[i];
        for (int i=0; i<n; i++)
            a[i]=aa[p[i]]+r;
        rec(0, done+1);     
        for (int i=0; i<n; i++)
            a[i]=aa[i];
    }
    else
    {
        for (int i=0; i<n; i++)
            a[i]=aa[p[i]]+r;
        rec(0, done+1);
        for (int i=0; i<n; i++)
            a[i]=aa[i];
    }
}

void solve()
{  
    cin>>n>>u>>r;
    for (int i=0; i<n; i++)
        cin>>a[i];
    for (int i=0; i<n; i++)
        cin>>b[i];
    for (int i=0; i<n; i++)
        cin>>k[i];
    for (int i=0; i<n; i++)
        cin>>p[i], --p[i];
    rec();
    cout<<answer;
}