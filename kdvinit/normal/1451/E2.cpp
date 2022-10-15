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

    int a[n+1];

    a[1]=0;
    for(int i=2;i<=n;i++)
    {
        cout<<"XOR "<<1<<" "<<i<<endl;
        cin>>a[i];
    }

    int x=0,y=0,freq[n]={0};
    freq[0]=1;
    for(int i=2;i<=n;i++)
    {
        if(freq[a[i]]==0) freq[a[i]]=i;
        else { x=freq[a[i]]; y=i; }
    }

    if(x==0)
    {
        int A;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==n-1) { A=i; break; }
        }

        int B;
        if(A==2) B=3;
        else B=2;

        int c,d,e;
        c=0;
        cout<<"AND "<<1<<" "<<B<<endl;
        cin>>d;
        cout<<"AND "<<A<<" "<<B<<endl;
        cin>>e;

        c*=2; c+=a[A];
        d*=2; d+=a[B];
        e*=2; e+=a[A]^a[B];

        a[1]=(c+d-e)/2;
    }
    else
    {
        int z;
        cout<<"AND "<<x<<" "<<y<<endl;
        cin>>z;

        a[1]=z^a[x];
    }

    for(int i=2;i<=n;i++) a[i]=a[i]^a[1];

    cout<<"! ";
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}