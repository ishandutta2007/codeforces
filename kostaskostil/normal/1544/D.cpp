#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qqq;
    cin>>qqq;
    for (int iii=0; iii<qqq; iii++)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for (int& i : a)
            cin>>i, i--;
        vector<vector<int> > g(n);

        vector<int> p(n, -1);
        for (int i=0; i<n; i++)
            g[a[i]].pb(i);
        for (int i=0; i<n; i++)
            if (g[i].size()>0)
                p[g[i][0]]=i;
        vector<int> ua, ub;
        for (int i=0; i<n; i++)
            if (p[i]==-1)
                ua.pb(i);
        for (int i=0; i<n; i++)
            if (g[i].size()==0)
                ub.pb(i);
        if (ua.size()==1)
        {
            if (ua[0] != ub[0])
                p[ua[0]] = ub[0];
            else
            {
                int t = a[ua[0]];
                int bk = g[t][0];
                p[bk] = ub[0];
                p[ua[0]] = t;
            }
        }
        else
        {
            int k = ua.size();
            for (int _=0; _<5; _++)
            for (int i = 0; i < k; i++)
                if (ua[i] == ub[i])
                    swap(ub[i], ub[(i+1)%k]);
            for (int i=0; i<k; i++)
                p[ua[i]]=ub[i];
        }
        int c = 0;
        for (int i=0; i<n; i++)
            if (p[i] == a[i])
                c++;
        cout<<c<<"\n";
        for (int i : p)
            cout<<i+1<<" ";
        cout<<"\n";
    }
}