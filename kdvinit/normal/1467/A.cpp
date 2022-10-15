/*
K.D. Vinit  |,,|
Hello
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    if(n==1) { cout<<9<<endl; return; }
    cout<<98;

    for(int i=3;i<=n;i++)
    {
        int x=(i+6)%10;
        cout<<x;
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