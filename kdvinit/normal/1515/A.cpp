/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, x;
    cin>>n>>x;
    int sum = 0;

    int a[n+1];
    for(int i=1; i<=n; i++) { cin>>a[i]; sum+=a[i]; }
    sort(a+1, a+n+1);

    if(sum==x) { cout<<"NO"<<endl; return; }
    sum=0;

    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++)
    {
        sum+=a[i];
        if(sum==x)
        {
            swap(a[i], a[i+1]);
            sum-=a[i+1];
            sum+=a[i];
        }
    }

    for(int i=1; i<=n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}