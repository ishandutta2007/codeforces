#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <memory.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair <int, int> pi;
typedef long double ld;
typedef long long li;
void solve();
int main ()
{
#ifndef ONLINE_JUDGE
        freopen ("in.txt", "r", stdin);
#endif
        int t=1;
        while (t--)
        solve();
        return 0;
}
#define int li
int n;
vector <int> e[5000];
pair <int, int> edges[5000];
int no;
bool be[5000];
int pred[5000];
void dfs (int v)
{
     be[v]=true;
     for (int i=0; i<e[v].size(); i++)
          if ( !be[e[v][i]] && ( (v!=edges[no].first || e[v][i]!=edges[no].second) && (e[v][i]!=edges[no].first || v!=edges[no].second) ) )
           {
                    dfs (e[v][i]);
                    pred[e[v][i]]=v;
           }
}
vector <int> cycle;
bool in[5000];
int ans[5000];
int d[5000];
int bfs (int v)
{
     queue <int> q;
     d[v]=0;
     q.push(v);
     while (!q.empty())
     {
          int cur=q.front();
          q.pop();
          for (int i=0; i<e[cur].size(); i++)
               if ( d[e[cur][i]]==-1 )
               {
                    if (in[e[cur][i]])
                         return d[cur]+1;
                    d[e[cur][i]]=d[cur]+1;
                    q.push(e[cur][i]);
               }
     }
}
void solve()
{
     cin>>n;
     for (int i=0; i<n; i++)
     {
          int q, w;
          cin>>q>>w;
          q--; w--;
          e[q].pb (w);
          e[w].pb (q);
          edges[i]=mp (q, w);
     }
     for (no=0; no<n; no++)
     {
          memset (pred, -1, sizeof pred);
          memset (be, false, sizeof be);
          dfs ( edges[no].first );
          if ( be[edges[no].second] )
          {
               int u=pred[edges[no].second];
               cycle.pb (edges[no].second);
               while (u!=-1)
               {
                    cycle.pb (u);
                    u=pred[u];
               }
               break;
          }
     }
     for (int i=0; i<cycle.size(); i++)
       {
          in[cycle[i]]=true;
          ans[cycle[i]]=0;
       }
     for ( int j=0; j<n; j++ )
          if (!in[j])
          {
               memset (d, -1, sizeof d);
               ans[j]=bfs (j);
          }
     for (int i=0; i<n; i++)
          cout<<ans[i]<<' ';
}