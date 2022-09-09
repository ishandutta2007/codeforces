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
#endif
    ios_base::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while (t--)
        solve();
    return 0;
}

//#define int li

int S, A, B, C;
ld s, a, b, c;

void solve()
{  
    cin>>S>>A>>B>>C;
    s=(ld)S;
    a=(ld)A;
    b=(ld)B;
    c=(ld)C;
    if (A==0 && B==0 && C==0)
    {
        printf ("%.10lf 0.0 0.0", s);
        return;
    }
    ld x=a/(a+b+c)*s, y=b/(a+b+c)*s, z=c/(a+b+c)*s;
    printf ("%.10lf %.10lf %.10lf", x, y, z);
}