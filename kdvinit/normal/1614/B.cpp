/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    array<int, 2> a[n+1];
    for(int i=1; i<=n; i++) { cin>>a[i][0]; a[i][1]=i; }
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);

    int ans[n+1];
    int tot=0;
    for(int i=1; i<=n; i++)
    {
        int dif = (i+1)/2;
        tot+=(2*dif*a[i][0]);
        if(i%2==1) dif*=-1;
        ans[a[i][1]]=dif;
    }

    cout<<tot<<endl;
    cout<<0<<" ";
    for(int i=1; i<=n; i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}