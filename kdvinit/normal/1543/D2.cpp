/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int k;

int xor_add(int x, int y)
{
    int ans=0, mul=1;
    while(x!=0 || y!=0)
    {
        int a = x%k;
        int b = y%k;
        int c = (a+b)%k;

        ans += (c*mul);

        mul*=k;
        x/=k;
        y/=k;
    }
    return ans;
}

int xor_sub(int x, int y)
{
    int ans=0, mul=1;
    while(x!=0 || y!=0)
    {
        int a = x%k;
        int b = y%k;
        int c = (a-b)%k;
        if(c<0) c+=k;

        ans += (c*mul);

        mul*=k;
        x/=k;
        y/=k;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n>>k;

    int tot=0, r, ask;
    for(int i=0; i<n; i++)
    {
        if(i%2==0) ask = xor_add(tot, i);
        else ask = xor_sub(tot, i);

        cout<<(ask)<<endl;

        cin>>r;
        if(r==1) return;

        tot = xor_sub(ask, tot);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}