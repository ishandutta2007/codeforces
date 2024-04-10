/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n,m,ans=0;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int cnt_left[n+1]={0};
    for(int j=1;j<=n;j++)
    {
        int cnt_right[n+1]={0};
        for(int k=n;k>j;k--)
        {
            ans+=((cnt_left[a[k]])*(cnt_right[a[j]]));
            cnt_right[a[k]]++;
        }
        cnt_left[a[j]]++;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}