/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int mod = 998244353;

void solve()
{
    int n;
    cin>>n;

    int a[n+1];

    int ans = 0, time[n+1];

    time[0]=0;
    ordered_set os;

    int x[n+1];

    x[0]=0;
    int lst=0;

    for(int i=1; i<=n; i++)
    {
        int tx, ty, s;
        cin>>tx>>ty>>s;

        x[i]=tx;

        int m=os.order_of_key(ty);
        os.insert(tx);

        int dif = tx-lst;
        time[i] = time[i-1] + dif;
        time[i]%=mod;

        ans += dif;
        ans%=mod;

        int xx =  time[i] - (time[m] + ty - x[m]);
        xx%=mod;

        int extra = xx;

        //cout<<i<<" "<<ans<<" "<<time[i]<<" "<<dif<<" "<<extra<<endl;

        time[i] += extra;
        time[i]%=mod;

        if(s==1) ans+=extra;
        ans%=mod;

        lst=tx;
    }
    ans++;

    ans%=mod;
    if(ans<0) ans+=mod;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}