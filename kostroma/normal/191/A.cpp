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

//#define int li

int n;
string q[1000500];
string s[1000500];
int dp[300][300];

void solve()
{  
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>q[i];
        s[i].pb(q[i][0]);
        s[i].pb(q[i][q[i].length()-1]);
    }
    for (int i=0; i<n; i++)
    {
        for (char c='a'; c<='z'; c++)
            if (dp[c][s[i][0]]>0)
                dp[c][s[i][1]]=max(dp[c][s[i][1]], dp[c][s[i][0]] + (int)q[i].length());
        dp[s[i][0]][s[i][1]]=max(dp[s[i][0]][s[i][1]], (int)q[i].length());
    }
    int ans=0;
    for (char c='a'; c<='z'; c++)
    {
        ans=max(ans, dp[c][c]);
    }
    cout<<ans;
}