/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;

    int freq[n+1]={0},a[n+1];
    for(int i=1;i<=n;i++) { cin>>a[i]; freq[a[i]]++; }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(freq[i]==1) { ans=i; break; }
    }

    if(ans==0) { cout<<-1<<endl; return; }

    for(int i=1;i<=n;i++)
    {
        if(a[i]==ans) { cout<<i<<endl; return; }
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}