#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <stdio.h>
#include <cmath>
#include <string>
#define pb push_back
#define sz size()
#define fi first
#define se second

using namespace std;

vector < pair < string, int > > v[10000];
vector < int > w[10000];
map < pair < string, int >, int > all;
pair < string, int > p[10000];
int d[10000];
vector < int > m;
set < int > cur;
queue < int > q;

bool eq(string a, string b)
{
    if(a.sz != b.sz)
        return false;
    for(int i = 0; i < a.sz; i++)
    {
        if(a[i] != b[i])
            return false;
    }
    return true;
}
void check(int x)
{
    int b = 0;
    for(int z : cur)
    {
        if(eq(p[x].fi, p[z].fi))
        {
            if(p[z].se <= p[x].se)
                b = z;
            else
                return;
        }
    }
    cur.insert(x);
    if(b)
        cur.erase(b);
}
void bfs()
{
    int cd = 1;
    q.push(0);
    d[0] = -1;
    while(!q.empty())
    {
        for(int x : w[q.front()])
        {
            if(d[x] == 0)
            {
                check(x);
                d[x] = cd;
            }
        }
        q.pop();
        if(q.empty())
        {
            for(int x : cur)
            {
                bool f = true;
                for(int t : m)
                {
                    if(eq(p[x].fi, p[t].fi))
                        f = false;
                }
                if(f)
                {
                    q.push(x);
                    m.pb(x);
                }
            }
            cd++;
            cur.clear();
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        cin >> p[i].fi >> p[i].se;
        all.insert(make_pair(p[i], i));
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++)
        {
            string s;
            int d;
            cin >> s;
            scanf("%d", &d);
            v[i].pb(make_pair(s, d));
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(pair < string, int > o : v[i])
        {
            w[i].pb(all[o]);
        }
    }
    m.pb(0);
    bfs();
    map < string, int > ans;
    for(int i : m)
    {
        if(i)
            ans.insert(p[i]);
    }
    cout << ans.sz << '\n';
    for(auto i : ans)
        cout << i.fi << ' ' << i.se << '\n';
}