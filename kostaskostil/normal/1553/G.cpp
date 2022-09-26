#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

//typedef long long ll;
//#define int ll

vector<int> prs;
const int nmax = 150500;
int a[nmax];
int p[nmax];

int get(int i)
{
    if (i==p[i])
        return i;
    return p[i] = get(p[i]);
}

void un(int i, int j)
{
    i = get(i);
    j = get(j);
    if (rand()%2)
        swap(i, j);
    p[i] = j;
}

map<int, vector<int> > byprime;
set<int> primes;
set<pair<int, int> > good;
vector<int> byind[nmax];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=2; i<=1000; i++)
    {
        bool ok = true;
        for (int j : prs)
            if (i%j==0)
                ok = false;
        if (ok)
            prs.pb(i);
    }
    int n;
    cin>>n;
    int q;
    cin>>q;
    for (int i=1; i<=n; i++)
        p[i] = i;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        int r = a[i];
        for (int j:prs)
        {
            if (j * j > r)
                break;
            if (r%j == 0)
                primes.insert(j), byprime[j].pb(i), byind[i].pb(j);
            while (r%j == 0)
                r/=j;
        }
        if (r > 1)
            primes.insert(r), byprime[r].pb(i), byind[i].pb(r);
    }
    for (auto& pa :byprime)
    {
        for (size_t i = 0; i + 1 < pa.se.size(); i++)
            un(pa.se[i], pa.se[i+1]);
    }
    for (int i=1; i<=n; i++)
    {
        vector<int> nw;// byind[i];

        int r = a[i] + 1;
        for (int j:prs)
        {
            if (j * j > r)
                break;
            if (r%j == 0)
                nw.pb(j);
            while (r%j == 0)
                r/=j;
        }
        if (r > 1)
            nw.pb(r);

        set<int> grs = {get(i)};
        for (int j : nw)
            if (primes.count(j))
        {
            int g = get(byprime[j][0]);
            grs.insert(g);
        }
        vector<int> gs;
        for (int j : grs)
            gs.pb(j);
        for (size_t i=0; i<gs.size(); i++)
            for (size_t j=i+1; j<gs.size(); j++)
                good.insert({gs[i], gs[j]});
    }
    for (int i=1; i<=q; i++)
    {
        int a, b;
        cin>>a>>b;
        if (get(a) == get(b))
            cout<<"0\n";
        else
        {
            if (good.count({get(a), get(b)}) or
                good.count({get(b), get(a)}))
            cout<<"1\n";
            else
            cout<<"2\n";
        }
    }
}