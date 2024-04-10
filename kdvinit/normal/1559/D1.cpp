/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 1005;

int parent[2][mxn];
int siz[2][mxn];

void make_set(int v, int i)
{
   parent[i][v] = v;
   siz[i][v] = 1;
}

int find_set(int v, int i)
{
   if (v == parent[i][v]) return v;
   return parent[i][v] = find_set(parent[i][v], i);
}

bool union_sets(int a, int b, int i)
{
   a = find_set(a, i);
   b = find_set(b, i);
   if (a == b) return true;

   if (siz[i][a] < siz[i][b]) swap(a, b);
   parent[i][b] = a;
   siz[i][a] += siz[i][b];
   return false;
}

void solve()
{
    int n, m1, m2;
    cin>>n>>m1>>m2;

    for(int i=1; i<=n; i++) make_set(i, 0), make_set(i, 1);
    for(int i=1; i<=m1; i++)
    {
        int u, v;
        cin>>u>>v;
        union_sets(u, v, 0);
    }
    for(int i=1; i<=m2; i++)
    {
        int u, v;
        cin>>u>>v;
        union_sets(u, v, 1);
    }

    int ans = 0;
    vector<int> ax, ay;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(find_set(i, 0) == find_set(j, 0)) continue;
            if(find_set(i, 1) == find_set(j, 1)) continue;
            ans++;
            union_sets(i, j, 0);
            union_sets(i, j, 1);
            ax.push_back(i);
            ay.push_back(j);
        }
    }

    cout<<ans<<endl;
    for(int i=0; i<ans; i++) cout<<ax[i]<<" "<<ay[i]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}