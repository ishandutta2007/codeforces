#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

typedef long long ll;
#define int ll

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
    {
        int n;
        int c=0;
        cin>>n;
        vector<int> v(n);
        for (int& i : v)
            cin>>i, i*=1e9, i-=(c++);
        auto u = v;
        sort(u.begin(), u.end());
        if ((n%2==0) or (u != v))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }

}