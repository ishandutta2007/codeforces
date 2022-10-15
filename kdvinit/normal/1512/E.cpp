/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, l, r, s;
    cin>>n>>l>>r>>s;

    int m = r-l+1;

    int mn = ((m)*(m+1))/2;
    int mx = 0;

    int b[m+1];
    for(int i=1; i<=m; i++)
    {
        b[i]=i+n-m;
        mx+=b[i];
    }

    if(s<mn || s>mx) { cout<<-1<<endl; return; }
    s-=mx;

    for(int i=1; i<=m; i++)
    {
        while(b[i]!=i && s!=0)
        {
            b[i]--;
            s++;
        }
    }

    int a[n+1];
    int freq[n+1]={0};
    for(int i=1; i<=m; i++)
    {
        a[l-1+i] = b[i];
        freq[b[i]]=1;
    }
    int ind=1;

    for(int i=1; i<=n; i++)
    {
        if(l<=i && i<=r) continue;

        while(freq[ind]==1) ind++;
        a[i]=ind;
        freq[ind]=1;
    }

    for(int i=1; i<=n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}