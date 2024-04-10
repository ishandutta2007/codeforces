#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<int> cost;
vector<bool> used;
vector<int> sum;
int all = 0;
vector<int> res;
vector<int> end1;
vector<bool> kor;
vector<vector<int> > g;

void dfs(int v, int p)
{
    used[v] = true;
    sum[v] += cost[v];
    for(int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        if(!used[u])
        {
            dfs(u, v);
        }
    }
    all += sum[v];
    if(sum[v] >= 0 && p != -1)
    {
        sum[p] += sum[v];
        res.push_back(v);
    }
    else
    {
        end1.push_back(v);
    }
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    kor.assign(n, false);
    cost.resize(n);
    g.resize(n);
    used.assign(n, false);
    sum.assign(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if(a != -1)
        {
            g[a - 1].push_back(i);
        }
        else
        {
            kor[i] = true;
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(kor[i])
        {
            dfs(i, -1);
        }
    }
    cout << all << endl;
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] + 1 << " ";
    }
    for(int i = end1.size() - 1; i >= 0; i--)
    {
        cout << end1[i] + 1 << " ";
    }
}
// 6 10 14 15 33
//51