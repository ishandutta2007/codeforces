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
        int mx = 0;
        int n; cin>>n;
        for (int x, i=1; i<=n; i++)
            cin>>x, mx = max(mx, x-i);
        cout<<mx<<"\n";
    }

}