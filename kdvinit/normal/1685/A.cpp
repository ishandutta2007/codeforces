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

    map<int, int> mp;
    int a[n+1];
    for(int i=1; i<=n; i++) { cin>>a[i]; mp[a[i]]++; }
    sort(a+1, a+n+1);

    if(n%2==1) { cout<<"NO"<<endl; return; }

    int m=n/2;
    int j=m, k=0;
    int b[n+1];

    for(int i=1; i<=m; i++)
    {
        b[++k]=a[i];
        b[++k]=a[++j];
    }

    for(int i=2; i<=n; i++)
    {
        if(b[i]==b[i-1]) { cout<<"NO"<<endl; return; }
    }

    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++) cout<<b[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}