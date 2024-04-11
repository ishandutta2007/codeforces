#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second

using namespace std;
const int nmax=5e5+100;
#define int long long

vector<int> g[nmax];
int sz[nmax];
int p[nmax];
int d[nmax];
int dfs(int v, int pr=-1, int l=0)
{
    d[v]=l;
    p[v]=pr;
    sz[v]=1;
    for (int i:g[v])
        if (i!=pr)
            sz[v]+=dfs(i, v, l+1);
    return sz[v];
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin>>n>>k;
    for (int x, y, i=1; i<n; i++)
    {
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    dfs(1);
    set<pair<int, int> > st;
    int ans=0;
    st.insert({sz[1]-1, 1});
    for (int i=1; i<=n-k; i++)
    {
//    cout<<"here"<<endl;
//    cout<<st.size()<<endl;
        auto pa=*prev(st.end());
        ans+=pa.fi;
        st.erase(prev(st.end()));
        for (int i:g[pa.se])
            if (i!=p[pa.se])
                st.insert({sz[i]-1 - d[i], i});
    }
    cout<<ans<<"\n";
}