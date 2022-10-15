/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    sort(a+1,a+n+1);
    int m=(n+1)/2;
    int cnt=1;

    cout<<a[m]<<" ";
    n--;
    while(n--)
    {
        m+=cnt;
        cout<<a[m]<<" ";
        if(cnt<0) cnt--;
        else cnt++;
        cnt*=-1;
    }
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}