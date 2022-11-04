#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<int> > g;
vector<int> a;
int n;

pair<bool, int> dfs(int v, int p)
{
    int sum = 0;
    if(g[v].size() == 0)
    {
        if(a[v] <= p)
        {
            return make_pair(true, p - a[v]);
        }
        return make_pair(false, -1);
    }
    for(int i = 0; i < g[v].size(); i++)
    {
        int u = g[v][i];
        pair<bool, int> res = dfs(u, p);
        if(!res.first)
        {
            return make_pair(false, -1);
        }
        sum += res.second;
        if(sum > 1000000000000000ll)
        {
            sum -= res.second;
        }
    }
    sum -= a[v];
    if(sum < 0)
    {
        return make_pair(false, -1);
    }
    return make_pair(true, sum);
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    g.resize(n);
    a.resize(n);
    for(int i = 0; i < n - 1; i++)
    {
        int p;
        cin >> p;
        g[p - 1].push_back(i + 1);
    }
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = -1;
    int r = 200000000000000ll;
    while(r - l > 1)
    {
        int mid = (l + r) / 2;
        if(dfs(0, mid).first)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << r;
}