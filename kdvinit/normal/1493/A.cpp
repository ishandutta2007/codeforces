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

    int m = k/2;
    cout<<m+n-k<<endl;
    if(k%2==1) m++;
    for(int i=m; i<k; i++) cout<<i<<" ";
    for(int i=k+1; i<=n; i++) cout<<i<<" ";
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}