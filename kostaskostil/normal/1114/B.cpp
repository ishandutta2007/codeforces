#pragma GCC optimize("O3")

#include <bits/stdc++.h>

#define fi first
#define se second
#define dist d
#define add disadd
#define pb push_back

#define int long long
using namespace std;

int n;

vector<pair<int, int> > a;
vector<int> t;

main()
{
    int m, k;
    cin>>n>>m>>k;
    int x;
    for (int i=1; i<=n; i++)
        cin>>x, a.pb({x, i});
    sort(a.begin(), a.end());
    int s=0;
    for (int i=n-1; i>=n-k*m; i--)
        s+=a[i].fi, t.pb(a[i].se);
    sort(t.begin(), t.end());
    cout<<s<<"\n";
    for (int i=1; i<k; i++)
        cout<<t[m*i-1]<<" ";
}