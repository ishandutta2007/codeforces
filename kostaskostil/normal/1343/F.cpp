#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int nmax=210;

int n;
vector<int> v[210];
set<int> pos[210];
set<int> pos_[210];

int mas[210];
set<pair<int, int> > st;
void upd(int pos, int val)
{
    st.erase({mas[pos], pos});
    mas[pos]=val;
    st.insert({mas[pos], pos});
}

vector<int> res;
bool try_first(int c)
{
    st.clear();
    for (int i=1; i<=n; i++)
        pos[i]=pos_[i];
    for (int i=1; i<=n; i++)
        upd(i, pos[i].size());
    st.erase({mas[c], c});
    res.clear();
    for (int i=1; i<n; i++)
    {
        if ((*st.begin()).fi!=1)
            return false;
        int x=(*st.begin()).se;
        res.pb(x);
        int t=*pos[x].begin();
        for (int i:v[t])
            if (i!=c)
            {
                upd(i, mas[i]-1);
                pos[i].erase(t);
            }
        st.erase({mas[x], x});
    }
    res.pb(c);
    res.pb(0);
    reverse(res.begin(), res.end());
    vector<int> poss(n+1);
    for (int i=1; i<=n; i++)
        poss[res[i]]=i;
    set<int> r;
    for (int i=2; i<=n; i++)
    {
        int mn=1e9, mx=-1e9;
        for (int j:v[i])
            mn=min(mn, poss[j]), mx=max(mx, poss[j]);
        if (mx-mn+1 != v[i].size())
            return false;
        r.insert(mx);
    }
    return (r.size()==n-1);
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        cin>>n;
        for (int i=1; i<=n; i++)
            pos_[i].clear();
        for (int t=2; t<=n; t++)
        {
            int k;
            cin>>k;
            v[t].resize(k);
            for (int i=0; i<k; i++)
                cin>>v[t][i], pos_[v[t][i]].insert(t);
        }
        for (int i=1; i<=n; i++)
            if (try_first(i))
            {
                for (int j=1; j<=n; j++)
                    cout<<res[j]<<" ";
                cout<<"\n";
                break;
            }
    }
}