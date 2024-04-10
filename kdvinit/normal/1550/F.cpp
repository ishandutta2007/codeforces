/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5;
const int mxn = 2e5 + 5;
const int Infi = 1e9;
const int Ninfi = -1e9;

int parent[mxn];
int siz[mxn];

vector< array<int, 2> > adj[N];
int a[N];
int Max_K[N];

void DFS(int chi, int par)
{
    for(auto x: adj[chi])
    {
        int v=x[0], w=x[1];
        if(v==par) continue;
        Max_K[v] = max(Max_K[chi], w);
        DFS(v, chi);
    }
}

void make_set(int v)
{
    parent[v] = v;
    siz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}

bool union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a == b) return true;

    if (siz[a] < siz[b]) swap(a, b);
    parent[b] = a;
    siz[a] += siz[b];
    return false;
}

void solve()
{
    int n, q, s, d;
    cin>>n>>q>>s>>d;

    map<int, int> mp;
    set<int> st;    st.insert(Infi);    st.insert(Ninfi);
    for(int i=1; i<=n; i++) cin>>a[i], mp[a[i]]=i, st.insert(a[i]), make_set(i);

    while(1)
    {
        int mx = siz[find_set(1)];
        if(mx==n) break;

        vector<int> comp[n+1];
        for(int i=1; i<=n; i++) comp[find_set(i)].push_back(i);

        vector< array<int, 3> > edges;      //u, v, w;
        for(int i=1; i<=n; i++)
        {
            int m = comp[i].size();
            if(m==0) continue;

            for(int j: comp[i]) st.erase(a[j]);

            int u, v, val=Infi;
            for(int j: comp[i])
            {
                int x = a[j]-d;
                auto nxp = st.upper_bound(x);   int nv = *nxp;
                nxp--;      int pv = *nxp;

                int dif = nv-x;
                if(nv!=Infi && dif<val) { val=dif; u=j; v=mp[nv]; }

                dif = x-pv;
                if(pv!=Ninfi && dif<val) { val=dif; u=j; v=mp[pv]; }

                x = a[j]+d;
                nxp = st.upper_bound(x);   nv = *nxp;
                nxp--;      pv = *nxp;

                dif = nv-x;
                if(nv!=Infi && dif<val) { val=dif; u=j; v=mp[nv]; }

                dif = x-pv;
                if(pv!=Ninfi && dif<val) { val=dif; u=j; v=mp[pv]; }
            }
            edges.push_back({u, v, val});

            for(int j: comp[i]) st.insert(a[j]);
        }


        for(auto x: edges)
        {
            int u=x[0], v=x[1], w=x[2];
            if(union_sets(u, v)) continue;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

    }

    Max_K[s]=0;
    DFS(s, -1);

    while(q--)
    {
        int i, k;
        cin>>i>>k;

        if(k>=Max_K[i]) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}