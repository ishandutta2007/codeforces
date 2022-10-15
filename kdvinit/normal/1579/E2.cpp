/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define int long long
#define endl "\n"

int solve()
{
    int n;
    cin>>n;


    map<int, int> mp;
    ordered_set os;
    int ans=0;

    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        int l1 = os.order_of_key({x, -1});
        int l2 = os.size() - os.order_of_key({x, mp[x]+10});
        ans += min(l1, l2);
        os.insert({x, ++mp[x]});
    }

    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) cout<<solve()<<endl;
    return 0;
}