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
    while (t--)
        solve();
    return 0;
}

#define int li

int n, k;
vector <int> e[100500];
int dp[50050][600];
int sums[50500][600];

bool be[100500];

int answer=0;

void dfs (int v, int p=-1)
{
    be[v]=true;
    dp[v][0]=1;
    for (int i=0; i<e[v].size(); i++)
        if (e[v][i]!=p)
        {
            int to=e[v][i];
            dfs(to, v);
            for (int j=1; j<=k; j++)
                dp[v][j]+=dp[to][j-1];
        }
    int add=0;
    for (int i=0; i<e[v].size(); i++)
        if (e[v][i]!=p)
        {
            int to=e[v][i];
            for (int j=0; j<k-1; j++)
            {
                add+=dp[to][j]*(dp[v][k-j-1]-((k-j-2>=0)?dp[to][k-j-2]:0));
            }
        }
    answer+=add/2;
    answer+=dp[v][k];
    //cout<<v<<' '<<answer<<endl;
}

void solve()
{  
    cin>>n>>k;
    for (int i=0; i<n-1; i++)
    {
        int q, w;
        cin>>q>>w;
        q--; w--;
        e[q].pb(w);
        e[w].pb(q);
    }
    dfs(0);
    cout<<answer;
}