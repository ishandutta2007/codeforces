/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

int lcm(int x, int y)
{
    int z = GCD(x, y);
    int ans = (x*y)/z;
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int b[n+2];
    b[1]=a[1];
    b[n+1]=a[n];

    for(int i=2; i<=n; i++) b[i]=lcm(a[i-1], a[i]);

    for(int i=1; i<=n; i++)
    {
        int x = GCD(b[i], b[i+1]);
        if(x==a[i]) continue;
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}