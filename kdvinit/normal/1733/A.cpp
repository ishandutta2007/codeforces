/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, k;
    cin>>n>>k;

    int a[n+1];
    int mx[k]={0};

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        int j=i%k;
        mx[j]=max(mx[j], a[i]);
    }

    int sum=0;
    for(int i=0; i<k; i++) sum+=mx[i];
    cout<<sum<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}