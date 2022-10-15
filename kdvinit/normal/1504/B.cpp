/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i] = x-'0';
    }
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        b[i] = x-'0';
    }

    int sum=0;
    int j = 0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==1) sum++;
        else sum--;

        if(sum!=0) continue;

        if(a[j+1]!=b[j+1])
        {
            for(int k=j+1; k<=i; k++) a[k]^=1;
        }

        j=i;
    }

    for(int i=1; i<=n; i++)
    {
        if(a[i]!=b[i]) { cout<<"NO"<<endl; return; }
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