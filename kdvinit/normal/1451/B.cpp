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
    int n,q;
    cin>>n>>q;

    char x;
    int a[n+1];
    for(int i=1;i<=n;i++) { cin>>x; a[i]=x-'0'; }

    int mn[2]={0},mx[2];
    for(int i=1;i<=n;i++)
    {
        if(mn[a[i]]==0) mn[a[i]]=i;
        mx[a[i]]=i;
    }

    while(q--)
    {
        int l,r;
        cin>>l>>r;

        if(mn[a[l]]<l || mx[a[r]]>r) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}