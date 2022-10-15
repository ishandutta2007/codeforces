/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin>>n>>k;

    while(k!=3) { cout<<1<<" "; k--; n--; }

    if(n%2==1)
    {
        cout<<1<<" "<<(n/2)<<" "<<(n/2)<<endl;
    }
    else
    {
        if(n%4==0)
        {
            cout<<(n/2)<<" "<<(n/4)<<" "<<(n/4)<<endl;
        }
        else
        {
            cout<<2<<" "<<((n-2)/2)<<" "<<((n-2)/2)<<endl;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}