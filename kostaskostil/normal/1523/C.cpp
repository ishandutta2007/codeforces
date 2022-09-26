#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

typedef long long ll;
#define int ll

using namespace std;

const int nmax = 1e6 + 100;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qqq;
    cin>>qqq;
    while (qqq--)
    {
        int n;
        cin>>n;

        int x;
        cin>>x;
        vector<int> v = {1};
        cout<<1<<"\n";

        for (int i=1; i<n; i++)
        {
            cin>>x;
            if (x!=1)
            {
                while (true)
                {
                    if (v.back() + 1 == x)
                        break;
                    v.pop_back();
                }
                v.pop_back();
            }
            v.pb(x);
            for (int i=0; i<v.size(); i++)
            {
                cout<<v[i];
                if (i+1==v.size())
                    cout<<"\n";
                else
                    cout<<".";
            }
        }
    }
}