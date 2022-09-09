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

int n, m;
int f[100500];
vector <int> e[100500];
vector <int> rev[100500];

bool one[100500], two[100500];
bool been[100500];

void dfs1 (int v)
{
    if (been[v])
        return;
    been[v]=true;
    one[v]=true;
    for (int i=0; i<e[v].size(); i++)
    {
        int to=e[v][i];
        one[to]=true;
        if (f[to]!=1)
            dfs1(to);
    }
}

void dfs2 (int v)
{
    if (been[v])
        return;
    been[v]=true;
    two[v]=true;
    for (int i=0; i<rev[v].size(); i++)
    {
        int to=rev[v][i];
        two[to]=true;
        if (f[to]!=1)
            dfs2(to);
    }
}

void solve()
{  
    cin>>n>>m;
    for (int i=0; i<n; i++)
        cin>>f[i];
    for (int i=0; i<m; i++)
    {
        int q, w;
        cin>>q>>w;
        q--; w--;
        e[q].pb(w);
        rev[w].pb(q);
    }
    for (int i=0; i<n; i++)
        if (f[i]==1)
            dfs1(i);
    memset (been, false, sizeof been);
    for (int i=0; i<n; i++)
        if (f[i]==2)
            dfs2(i);
    for (int i=0; i<n; i++)
        if (one[i] && two[i])
            cout<<1<<endl;
        else
            cout<<0<<endl;
}