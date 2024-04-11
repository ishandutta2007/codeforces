#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    for (int _=0; _<___; _++)
    {
        int n, u, v;
        cin>>n>>u>>v;
        vector<int> a(n);
        int pr = -1;
        bool ok = false;
        bool ok1 = false;
        for (int& i : a)
        {
            cin>>i;
            if (pr==-1)
            {
                pr=i;
                continue;
            }
            if (i!=pr)
                ok1=true;
            if (abs(i - pr) > 1)
                ok=true;
            pr=i;
        }


        if (ok)
            cout<<0<<"\n";
        else
        {
            if (ok1)
                cout<<min(u, v)<<"\n";
            else
                cout<<v+min(u,v)<<"\n";
        }
    }

}