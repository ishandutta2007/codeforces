/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define endl "\n"

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n, m;
    cin>>n>>m;

    array<int, 2> a[m+1];
    for(int i=1; i<=m; i++)
    {
        int x; cin>>x;
        a[i]={x, -i};
    }
    sort(a+1, a+m+1);

    int ans = 0;
    ordered_set os;

    for(int i=1; i<=m; i++)
    {
        int x = -a[i][1];
        int y = os.order_of_key(x);
        ans+=y;
        os.insert(x);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}