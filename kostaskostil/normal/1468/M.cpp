#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

const int C = 70;
const int nmax = 2e5+100;

int n, c;
vector<int> sets[nmax];

vector<pair<pair<int, int>, int> > v;
int cur[nmax];

void compress()
{
    c=0;
    map<int, int> mp;
    for (int i=1; i<=n; i++)
    {
        for (int&j : sets[i])
        {
            if (mp.count(j))
                j=mp[j];
            else
                j=(mp[j]=++c);
        }
        sort(sets[i].begin(), sets[i].end());
    }
}


void solve()
{
    cin>>n;
    for (int i=1; i<=n; i++)
        sets[i].clear();
    v.clear();

    for (int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        sets[i].resize(k);
        for (int& j:sets[i])
            cin>>j;
    }
    compress();
    for (int i=1; i<=n; i++) /// (M / C) * M
        if (sets[i].size() > C)
    {
        for (int j=1; j<=c; j++)
            cur[j]=0;
        for (int j: sets[i])
            cur[j]=1;
        for (int j=1; j<=n; j++)
            if (i!=j)
        {
            int cnt=0;
            for (int k:sets[j])
                if (cur[k])
            {
                cnt++;
                if (cnt==2)
                {
                    cout<<i<<" "<<j<<"\n";
                    return;
                }
            }
        }
    }

    for (int i=1; i<=n; i++)
        if (sets[i].size() <= C)
    {
        for (size_t j1=0; j1<sets[i].size(); j1++)
            for (size_t j2=j1+1; j2<sets[i].size(); j2++)
                v.pb({{sets[i][j1], sets[i][j2]}, i});
    }
    sort(v.begin(), v.end());
    for (size_t i=0; i+1<v.size(); i++)
        if (v[i].fi==v[i+1].fi)
        {
            cout<<v[i].se<<" "<<v[i+1].se<<"\n";
            return;
        }
    cout<<"-1\n";
    return;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    for (int _=0; _<t; _++)
    {
        solve();
    }
}