/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        char x; cin>>x;
        a[i]=x-96;
    }

    int val[n+1]={0};
    for(int i=1;i<=m;i++)
    {
        int x; cin>>x;
        val[x]++;
    }

    for(int i=n-1;i>0;i--)
    {
        val[i]+=val[i+1];
    }

    int freq[27]={0};
    for(int i=1;i<=n;i++)
    {
        freq[a[i]]+=val[i];
    }

    for(int i=1;i<=n;i++) freq[a[i]]++;
    for(int i=1;i<=26;i++) cout<<freq[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}