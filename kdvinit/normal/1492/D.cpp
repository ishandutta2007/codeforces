/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int a,b,k;
    cin>>a>>b>>k;

    if(k==0)
    {
        cout<<"Yes"<<endl;

        for(int i=1;i<=b;i++) cout<<1;
        for(int i=1;i<=a;i++) cout<<0;
        cout<<endl;

        for(int i=1;i<=b;i++) cout<<1;
        for(int i=1;i<=a;i++) cout<<0;
        cout<<endl;

        return;
    }

    int n=a+b;
    int ans1[n+1];
    int ans2[n+1];

    for(int i=1;i<=n;i++) ans1[i]=-1;
    for(int i=1;i<=n;i++) ans2[i]=-1;

    b--;
    ans1[1]=1;
    ans2[1]=1;

    if(a==0 || b==0) { cout<<"No"<<endl; return; }
    if(k>(n-2)) { cout<<"No"<<endl; return; }

    cout<<"Yes"<<endl;

    ans1[2]=1;
    ans2[2]=0;

    int j=2+k;
    ans1[j]=0;
    ans2[j]=1;

    a--;
    b--;
    for(int i=1;i<=n;i++)
    {
        if(ans1[i]!=-1) continue;
        if(b!=0)
        {
            ans1[i]=1;
            ans2[i]=1;
            b--;
        }
        else
        {
            ans1[i]=0;
            ans2[i]=0;
        }
    }

    for(int i=1;i<=n;i++) cout<<ans1[i];
    cout<<endl;
    for(int i=1;i<=n;i++) cout<<ans2[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}