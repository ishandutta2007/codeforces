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

int n, m;
string s[1010];
int dist[1010][1010];

vector <int> str[1010];
vector <int> stolb[1010];

bool lb[1010], tr[1010];

bool good (pair <int, int> cur)
{
    return cur.first>=0 && cur.first<n && cur.second>=0 && cur.second<m;
}

void solve()
{  
    cin>>n>>m;
    for (int i=0; i<n; i++)
        cin>>s[i];
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            if (s[i][j]=='#')
                str[i].pb(j), stolb[j].pb(i);
    str[n-1].pb(m);
    memset (dist, -1, sizeof dist);
    queue < pair < pair <int, int>, int > > q;
    q.push( mp ( mp(0, -1), 0 ) );
    while (!q.empty())
    {
        pair <pair <int, int>, int> curr=q.front();
        pair <int, int> cur=curr.first;
        q.pop();
        int d;
        if (cur.second>=0)
            d=dist[cur.first][cur.second];
        else
            d=0;
        if (curr.second%2)
        {
            if (lb[cur.second])
                continue;
            for (int i=0; i<stolb[cur.second].size(); i++)
            {
                pair <int, int> now=mp(stolb[cur.second][i], cur.second);
                if ( now!=cur && ( dist[now.first][now.second]==-1 ) )
                {
                    dist[now.first][now.second]=d+1;
                    q.push( mp(now, 0) );
                }
            }
            lb[cur.second]=true;
        }
        else
        {
            if (tr[cur.first])
                continue;
            for (int i=0; i<str[cur.first].size(); i++)
            {
                pair <int, int> now=mp(cur.first, str[cur.first][i]);
                if ( now!=cur && ( dist[now.first][now.second]==-1 ) )
                {
                    dist[now.first][now.second]=d+1;
                    q.push( mp(now, 1) );
                }
            }
            tr[cur.first]=true;
        }    
    }
    if (dist[n-1][m]==-1)
    {
        cout<<"-1";
        return;
    }
    cout<<dist[n-1][m]-1;
}