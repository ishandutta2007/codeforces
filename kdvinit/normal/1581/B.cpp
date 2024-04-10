/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int n, m, k;
    cin>>n>>m>>k;

    int mx = (n*(n-1))/2;
    if(m>mx || m<n-1) return false;

    int mn = 2;
    if(m==mx) mn=1;
    if(n==1) mn=0;

    return (mn<k-1);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}