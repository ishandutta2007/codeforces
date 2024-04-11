
#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

int L = 200;

vector<int> zapros(int x, int y, int h, int d)
{
    if (h)
        swap(x, y);
    vector<int> ans;
    for (int i = y / d; i <= (y + d - 1) / d; i++)
        ans.pb(x * i);
    return ans;
}

int all(int each, bool ver)
{
    vector<pair<int, int> > ask;
    for (int i=1; i<=L; i++)
        for (int j=1; j<=L; j++)
    {
        if (ver)
            if (i%each == 0)
                ask.pb({i, j});
        if (!ver)
            if (j%each == 0)
                ask.pb({i, j});
    }
    cout<<"? "<<ask.size()<<"\n";
    for (auto pa : ask)
        cout<<pa.fi<<" "<<pa.se<<" ";
    cout<<endl;

    int res;
    cin>>res;
    return res;
}


vector<pair<int, int> > f(vector<pair<int, int> > ars)
{
    int ans = 1e9;
    pair<int, int> mv;
    for (int h = 0; h <= 1; h++)
        for (int d = 2; d <= L; d++)
        {
            map<int, int> mp;
            for (auto pa : ars)
                for (int i : zapros(pa.fi, pa.se, h, d))
                    mp[i]++;
            int mx=0;
            for (auto pa : mp)
                mx=max(mx, pa.se);
            if (mx < ans)
                ans = mx, mv = {d, h};
        }
    auto res = all(mv.fi, mv.se);
    vector<pair<int, int> > rs;
    for (auto pa : ars)
    {
        for (int i : zapros(pa.fi, pa.se, mv.se, mv.fi))
            if (i == res)
                rs.pb(pa);
    }
    return rs;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int s = all(1, 0);
    vector<pair<int, int> > ars;
    for (int i=2; i<=min(L, s-1); i++)
        if (s%i==0)
            ars.pb({i, s/i});
    for (int i =1; i<=3; i++)
//    while (ars.size() > 1)
        ars = f(ars);
    int q = rand()%ars.size();
    cout<<"! "<<(ars[q].fi - 1 + ars[q].se - 1) * 2<<"\n";
}