/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void printx(int x)
{
    for(int i=1; i<=x; i++) cout<<"(";
    for(int i=1; i<=x; i++) cout<<")";
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        printx(i);
        printx(n-i);
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}