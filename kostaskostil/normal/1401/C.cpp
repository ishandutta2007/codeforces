#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int long long

main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for (int&i:v) cin>>i;

        auto vx=v;
        sort(v.begin(),v.end());
        int a=v[0];

        bool ok=true;

        multiset<int> div;
        multiset<int> undiv;
        for (int i:vx)
        {
            if (i%a==0) div.insert(i);
            else undiv.insert(i);
        }
        vector<int> res;
        for (int i:vx)
        {
            if (i%a==0)
            {
                res.pb(*div.begin());
                div.erase(div.begin());
            }
            else
            {
                res.pb(i);
            }
        }
        ok=(res==v);
        if (ok) cout<<"YES\n";
        else cout<<"NO\n";
    }

    return 0;
}