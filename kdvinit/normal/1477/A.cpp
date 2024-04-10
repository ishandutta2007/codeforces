/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int x,int y)
{
    if(x%y==0) return y;
    else return gcd(y,x%y);
}

void solve()
{
    int n,k;
    cin>>n>>k;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    k-=a[1];
    int mn=abs(a[2]-a[1]);
    for(int i=3;i<=n;i++)
    {
        int x=abs(a[i]-a[1]);
        mn=gcd(mn,x);
    }

    if(k%mn==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}