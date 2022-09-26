#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

typedef long long ll;
#define int ll

using namespace std;

const int nmax = 2e5 + 100;

string s;

vector<int> merg(vector<int> v1, vector<int> v2, int j2, int r)
{
    vector<int> p1(v1.size());
    vector<int> p2(v2.size());
    for (size_t i=0; i<v1.size(); i++)
        p1[v1[i]]=i;
    for (size_t i=0; i<v2.size(); i++)
        p2[v2[i]]=i;

    vector<int> ans(v1.size() + v2.size());
    int i1 = 0;
    int i2 = 0;
    int j = j2;
    while (j < r)
    {
        if (s[j] == '0')
        {
            ans[p1[i1] ] = j-j2;
            i1++;
            j++;
            if (i1 == v1.size())
                break;
        }
        else
        {
            ans[v1.size() + p2[i2] ] = j-j2;
            i2++;
            j++;
            if (i2 == v2.size())
                break;
        }
    }
    if (j!=r)
        return {};
    if ((i1 < v1.size()) and (i2 < v2.size()))
        return {};
    while (i1 < v1.size())
    {
        ans[p1[i1]] = j-j2;
        i1++;
        j++;
    }
    while (i2 < v2.size())
    {
        ans[v1.size() + p2[i2]] = j-j2;
        i2++;
        j++;
    };
    return ans;
}

map<pair<int, int>, vector<pair<vector<int>, int> > > dp;

vector<pair<vector<int>, int> > solve(int r, int n)
{
    #define cry return dp[{r, n}] = {}
    if (n==1)
    {
        return {{{0}, r}};
    }
//    cout<<r<<" "<<n<<"\n";
    if (dp.count({r, n}))
        return dp[{r, n}];

    int ls = n/2;
    int rs = (n+1)/2;
    int l = r-1;
    int c1 = 0;
    int c2 = 0;

    vector<pair<vector<int>, int> > ans;
    while (true)
    {
        if (s[l] == '0')
            c1++;
        if (s[l] == '1')
            c2++;
        if ((c1 > ls) or (c2 > rs))
            break;
        if ((c1==ls) or (c2==rs))
        {
            while (true)
            {
                auto par0 = solve(l, rs);
                for (auto par : par0)
                {
                    auto pal0 = solve(par.se, ls);
                    for (auto pal : pal0)
                    {
                        auto ans0 = merg(pal.fi, par.fi, l, r);
                        if (ans0.size() > 0)
                            ans.pb({ans0, pal.se});
                    }
                }
                break;
            }
        }
        l--;
        if (l<0)
            break;
    }
    return dp[{r, n}] = ans;
    #undef cry
}

main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    cin>>s;

    for (int n = 1; ; n++)
    {

        auto q = solve(s.size(), n);
        for (auto v : q)
            if (v.se == 0)
        {
        cout<<v.fi.size()<<"\n";

        for (int i : v.fi)
            cout<<i+1<<" ";
        cout<<"\n";
        return 0;
        }

    }
}
// 101011010001100100011011001111011000011110010