/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int num_bits(int k)
{
    int ans=0;
    while(k!=0) { k/=2; ans++; }
    return ans;
}

void print(int a[], int n)
{
    for(int i=1; i<=n; i++) cout<<a[i]<<" ";
    cout<<endl;
}

void solve()
{
    int n, k;
    cin>>n>>k;
    k--;

    int mx = num_bits(k);
    if(mx>=n) { cout<<-1<<endl; return; }

    int ans[n+1];
    int fix=n-mx-1;

    for(int i=1; i<=fix; i++) ans[i]=i;

    int bit[mx+1];
    for(int i=mx-1; i>=0; i--) { bit[i]=k%2; k/=2; }
    bit[mx]=0;

    int lst=fix;
    for(int i=0; i<=mx; i++)
    {
        int j=i;
        while(bit[j]!=0) j++;

        for(int i2=j; i2>=i; i2--) ans[fix+i2+1] = ++lst;
        i=j;
    }

    print(ans, n);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}