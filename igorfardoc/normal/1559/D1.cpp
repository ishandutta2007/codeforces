#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int get_class(int a, vector<int>& mass)
{
    if(a == mass[a])
    {
        return a;
    }
    int par = get_class(mass[a], mass);
    mass[a] = par;
    return par;
}

void join(int a, int b, vector<int>& mass, vector<int>& sz)
{
    int par1 = get_class(a, mass);
    int par2 = get_class(b, mass);
    if(par1 == par2)
    {
        return;
    }
    if(sz[par1] > sz[par2])
    {
        sz[par1] += sz[par2];
        mass[par2] = par1;
    }
    else
    {
        sz[par2] += sz[par1];
        mass[par1] = par2;
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<int> mass1(n), mass2(n), sz1(n, 1), sz2(n, 1);
    for(int i = 0; i < n; i++)
    {
        mass1[i] = i;
        mass2[i] = i;
    }
    for(int i = 0; i < m1; i++)
    {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        join(v, u, mass1, sz1);
    }
    for(int i = 0; i < m2; i++)
    {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        join(v, u, mass2, sz2);
    }
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(get_class(i, mass1) != get_class(j, mass1) && get_class(i, mass2) != get_class(j, mass2))
            {
                ans.push_back({i, j});
                join(i, j, mass1, sz1);
                join(i, j, mass2, sz2);
            }
        }
    }
    cout << ans.size() << '\n';
    for(auto& el : ans)
    {
        cout << el.first + 1 << ' ' << el.second + 1 << '\n';
    }
}