/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve()
{
    int n;
    cin>>n;

    vector< vector<int> > xv1(n),xv2(n),xv(n);
    int x;
    for(int i=0;i<n;i++) { cin>>x; xv1[i].push_back(x); }
    for(int i=0;i<n;i++) { cin>>x; xv1[i].push_back(x); }

    sort(xv1.begin(),xv1.end());

    for(int i=0;i<n;i++)
    {
        xv2[i].push_back(xv1[i][1]);
        xv2[i].push_back(xv1[i][0]);
    }

    sort(xv2.begin(),xv2.end());

    for(int i=0;i<n;i++)
    {
        xv2[i][0]=i+1;
    }

    for(int i=0;i<n;i++)
    {
        xv[i].push_back(xv2[i][1]);
        xv[i].push_back(xv2[i][0]);
    }

    sort(xv.begin(),xv.end());

    /*
    for(int i=0;i<n;i++) cout<<xv[i][0]<<" ";
    cout<<endl;
    for(int i=0;i<n;i++) cout<<xv[i][1]<<" ";
    cout<<endl;
    */

    int ans=0;
    ordered_set os;
    for(int i=0;i<n;i++)
    {
        int cnt=os.order_of_key(xv[i][1]);
        os.insert(xv[i][1]);
        //cout<<i<<" "<<xv[i][0]<<" "<<cnt<<endl;
        ans+=(xv[i][0]*cnt);
    }

    os.clear();
    for(int i=n-1;i>=0;i--)
    {
        int cnt=os.order_of_key(xv[i][1]);
        int m=n-1-i;
        cnt=m-cnt;
        //cout<<i<<" "<<xv[i][0]<<" "<<cnt<<endl;
        os.insert(xv[i][1]);
        ans-=(xv[i][0]*cnt);
    }
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}