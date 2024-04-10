
#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <ext\hash_set>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1e5+7;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

   vector<vector<int> > g(maxn);
int deg [maxn]={0}, son[maxn];

vector<int> ans(maxn,-1);

    void dfs(int v)
    {
        if (ans[v]!=-1)
            return;
        int best=-1;
        for (int i=0;i<g[v].size();i++)
        {
            if (ans[g[v][i]]==-1)
                dfs(g[v][i]);

            if (best==-1)
            {

                best=g[v][i];
                continue;
            }

            if (ans[g[v][i]]>ans[best])
            {
                best=g[v][i];
            }
        }

            ans[v]=ans[best]+1;
            //son[v]=son[best];

    }
int main()
{
    int n,m;
    //freopen("input.txt","r",stdin);

    scanf("%d %d",&n,&m);

    for (int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        x--;
        y--;
        if (x<y)
            g[y].pb(x);
        else
            g[x].pb(y);
        deg[x]++;
        deg[y]++;
    }

    int best=0;
    for (int i=0;i<n;i++)
        if (g[i].size()==0)
            {
                ans[i]=1;
             //   son[i]=i;
            }

    for (int i=0;i<n;i++)
    {
        if (ans[i]==-1)
        {
            dfs(i);
        }
    }

    for (int i=1;i<n;i++)
    {
       // cout<<son[i]<<endl;
        if (1LL*ans[i]*deg[i]>1LL*ans[best]*deg[best])
            best=i;
    }
    cout<<1LL*ans[best]*deg[best];
    return 0;
}