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

int LCM(int x, int y)
{
    int ans = x;
    ans/=(GCD(x, y));
    ans*=y;
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int lcm = 2;
    if(a[1]%2==0) { cout<<"NO"<<endl; return; }

    for(int i=2; i<=n; i++)
    {
        lcm = LCM(lcm, i+1);
        if(a[i]%lcm==0) { cout<<"NO"<<endl; return; }
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