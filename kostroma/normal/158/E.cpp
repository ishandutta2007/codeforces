#pragma hdrstop
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
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

#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    int t=1;
    while (t--)
        solve();
    return 0;
}

#define int li

int n, k;
int dp[5000][5000];
vector < pair <int, int> > a;
int b[5000];
void solve ()
{
    cin>>n>>k;
    a.pb(mp(1, 0));
    b[0]=1;
    for (int i=0; i<n; i++)
    {
        int q, w;
        cin>>q>>w;
        a.pb(mp(q, w));
        b[i+1]=q;
    }
    a.pb(mp(86401, 0));
    b[n+1]=86401;
    int border=0;
    for (int i=0; i<=n+5; i++)
        for (int j=0; j<=i; j++)
            dp[i][j]=(1LL<<50);
    dp[0][0]=1;
    for (int i=0; i<=n; i++)
        for (int j=0; j<=i; j++)
        {
            pair <int, int> cur=a[i+1];
            dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j]);
            int now=max(b[i+1], dp[i][j])+cur.second;
            dp[i+1][j]=min(dp[i+1][j], now);
        }
    int ans=0;
    for (int i=1; i<=n+1; i++)
    {
        for (int j=0; j<=k; j++)
        {
            int cur=dp[i-1][j];
            int now=b[i];
            ans=max(ans, now-cur);
        }
    }

    cout<<ans;

}