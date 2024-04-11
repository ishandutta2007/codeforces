#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int& i : v)
            cin>>i;
        bool ok = false;
        int s = 1;
        for (int i=0; i<n; i++)
            s*=3;
        for (int m = 1; m < s; m++)
        {
            int x=m;
            vector<int> t(n);
            for (int i=0; i<n; i++)
                t[i] = x%3, x/=3, t[i]--;
            int s = 0;
            int ab = 0;
            for (int i=0; i<n; i++)
                s+=v[i]*t[i], ab+=t[i]*t[i];
            if (s==0)
                if (ab>0)
                    ok=true;
        }
        if (ok)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}