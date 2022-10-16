/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int fact[16];

void do_small(int n,int cnt,int l,int r)
{
    int a[n+1];

    vector<int> per;
    for(int i=1;i<=n;i++) per.push_back(i);
    for(int i=1;i<=n;i++)
    {
        int y=( (cnt-1)/fact[n-i] );
        cnt-=y*fact[n-i];
        a[i]=per[y];
        per.erase(per.begin()+y);
    }

    int ans=0;
    for(int i=l;i<=r;i++) ans+=a[i];
    cout<<ans<<endl;
}

int val(int x,int a[],int n)
{
    int  ans;
    if(x<=n-15)
    {
        ans=( x*(x+1) )/2;
    }
    else
    {
        int y=n-15;
        ans=( y*(y+1) )/2;
        for(int i=y+1;i<=x;i++) ans+=a[i-y];
    }
    return ans;
}

void do_large(int n,int cnt,int l,int r)
{
    int a[16];

    vector<int> per;
    for(int i=1;i<=15;i++) per.push_back(i);
    for(int i=1;i<=15;i++)
    {
        int y=( (cnt-1)/fact[15-i] );
        cnt-=y*fact[15-i];
        a[i]=per[y];
        per.erase(per.begin()+y);
    }

    for(int i=1;i<=15;i++) a[i]+=(n-15);

    int ans=val(r,a,n)-val(l-1,a,n);
    cout<<ans<<endl;
}

void solve()
{
    int n,q;
    cin>>n>>q;

    fact[0]=1;
    for(int i=1;i<=15;i++) fact[i]=i*fact[i-1];

    int cnt=1,x,y,z;
    while(q--)
    {
        cin>>x;
        if(x==1)
        {
            cin>>y>>z;
            if(n<=15) do_small(n,cnt,y,z);
            else do_large(n,cnt,y,z);
        }
        else
        {
            cin>>y;
            cnt+=y;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}