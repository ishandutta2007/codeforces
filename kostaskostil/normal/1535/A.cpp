#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

typedef long long ll;
#define int ll

using namespace std;

const int nmax = 2e5 + 100;


main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin>>q;
    while (q--)
    {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        if (a<b) swap(a, b);
        if (c<d) swap(c, d);
        if (a > d and c > b)
            cout<<"YES\n";
        else 
            cout<<"NO\n";
    }
}