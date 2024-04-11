#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax=500500;
typedef long long ll;
#define int ll

istream& operator >> (istream& is, vector<int>& v)
{
    for (int& i:v)
        cin>>i;
    return is;
}

int n, m;
vector<int> g[nmax];
int t[nmax];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    int ttt;
//    cin>>ttt;
//    for (int iii=0; iii<ttt; iii++)
//    {
//    }
    cin>>n>>m;
    for (int i=1; i<=m; i++)
        {
            int x, y;
            cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }
    bool ok=true;
    vector<pair<int, int> > v;
    for (int i=1; i<=n; i++)
        cin>>t[i], v.pb({t[i], i});
    vector<int> ans;
    sort(v.begin(), v.end());
    for (auto pa:v)
    {
        int cur=pa.se;
        set<int> st;
        for (int i:g[pa.se])
        {
            if (t[i]==pa.fi)
                ok=false;
            if (t[i]<pa.fi)
            st.insert(t[i]);
        }
        if (st.size()==pa.fi-1)
            ans.pb(cur);
        else
            ok=false;
    }
    if (ok)
    {
        for (int i:ans)
            cout<<i<<" ";
        cout<<"\n";
    }
    else cout<<"-1\n";
}