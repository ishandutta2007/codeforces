#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax = 5e5 + 100;

typedef long long ll;
#define int ll

int n;
vector<int> g[nmax];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin>>n>>k;
    for (int i = 0; i < n; i++)
        for (int per = 0; per <= min(i, k); per ++)
    {
        int to = i + k - 2*per;
        if (i + k - per <= n)
            g[i].pb(to);
    }

    vector<int> p(n+1, -1);
    vector<int> l(n+1, -1);

    queue<int> q;
    q.push(0);
    l[0] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i : g[v])
            if (l[i] == -1)
        {
            l[i] = l[v] + 1;
            p[i] = v;
            q.push(i);
        }
    }

    if (l[n] == -1)
        cout<<"-1\n", exit(0);

    vector<int> v;
    int i = n;
    while (true)
    {
        v.pb(i);
        i = p[i];
        if (i==0)
            break;
    }
    reverse(v.begin(), v.end());

    int cur = 0;
    int ans = 0;
    set<int> boris;
    for (int i : v)
    {
        int per = (-i + cur + k) / 2;
//        cout<<per<<"\n";

        vector<int> nw;
        vector<int> ol;
        for (int j = 1; j <= n; j++)
        {
            if (boris.count(j))
            {
                if (ol.size() < per)
                    ol.pb(j), boris.erase(j);
            }
            else
            {
                if (nw.size() < k - per)
                    nw.pb(j), boris.insert(j);
            }
        }

        cout<<"? ";
        for (int i : nw)
            cout<<i<<" ";
        for (int i : ol)
            cout<<i<<" ";
        cout<<endl;

        int xorik;
        cin>>xorik;
        ans^=xorik;

        cur = i;
    }
    cout<<"! "<<ans<<endl;
}