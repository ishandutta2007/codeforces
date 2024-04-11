#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

int sq(int n)
{
    int ans = 0;
    for (int i=1; i<=n; i++)
        ans+=i*(n+1-i);
    return ans;
}
void solve()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for (int& i : v)
        cin>>i;
    vector<int> pos(n+1);
    pos[0] = 0;
    for (int i=0; i<n; i++)
        pos[i+1] = pos[i] + (v[i]==0);
    int ans = sq(n);
    for (int i=0; i<=n; i++)
        for (int j=i+1; j<= n; j++)
            ans+=pos[j]-pos[i];
    cout<<ans<<"\n";
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