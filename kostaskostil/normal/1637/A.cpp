#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int& i : v)
        cin>>i;
    vector<int> mx(n);
    vector<int> mn(n);
    mx[0] = v[0];
    for (int i=1; i<n; i++)
        mx[i] = max(mx[i-1], v[i]);
    mn[n-1] = v[n-1];
    for (int i=n-2; i>=0; i--)
        mn[i] = min(mn[i+1], v[i]);
    for (int i=0; i+1<n; i++)
    if (mx[i] > mn[i+1])
    {
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
        solve();
}