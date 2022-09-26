#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> p;
    for (int i=2; i<=100500; i++)
    {
        bool ok = true;
        for (int j : p)
        {
            if (i%j ==0)
                ok=false;
            if (!ok or j*j>i)
                break;
        }
        if (ok)
            p.pb(i);
    }

    int ___;
    cin>>___;
    while(___--)
    {
        int n, k;
        cin>>n>>k;
        vector<int> v(n);
        for (int& i: v)
        {
            cin>>i;
            for (int j : p)
            {
                if (j*j > i)
                    break;
                while (i%(j*j)==0)
                    i/=(j*j);
            }
        }
        int ans=0;
        int l=0;
        set<int> used;
        while (l<n)
        {
            if ((l==0) or (used.count(v[l])))
            {
                ans++;
                used.clear();
            }
            used.insert(v[l]);
            l++;
        }
        cout<<ans<<"\n";
    }
}