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

    int x[n+1];
    for(int i=1;i<=n;i++) cin>>x[i];

    int mn=0;

    for(int i=2;i<=n;i++)
    {
        int diff=abs(x[i]-x[i-1]);
        mn=gcd(mn,diff);
    }
    k-=x[1];
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