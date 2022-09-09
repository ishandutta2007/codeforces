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

#define int li

int n;

void solve()
{  
    cin>>n;
    if (n==1)
    {
        cout<<"0";
        return;
    }
    int sum=3;
    int ans=3;
    for (int i=1; i<n-1; i++)
    {
        sum*=3;
        sum%=1000000007;
        ans=sum-ans;
        ans%=1000000007;
    }
    if (ans<0)
        ans+=1000000007;
    cout<<ans;
}