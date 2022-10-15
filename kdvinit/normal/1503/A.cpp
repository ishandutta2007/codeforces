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

    int a[n+1], cnt0=0, cnt1=0;
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i] = x-'0';

        if(a[i]==0) cnt0++;
        else cnt1++;
    }

    if(cnt0%2==1)
    {
        cout<<"NO"<<endl;
        return;
    }

    int b[n+1], c[n+1];
    int c20=0;
    int c21=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==1)
        {
            c21++;
            if(2*c21>cnt1)
            {
                b[i]=-1;
                c[i]=-1;
            }
            else
            {
                b[i]=1;
                c[i]=1;
            }
        }
        else
        {
            c20++;
            if(c20%2==1)
            {
                b[i]=1;
                c[i]=-1;
            }
            else
            {
                b[i]=-1;
                c[i]=1;
            }
        }
    }

    int sum1=0, sum2=0;
    for(int i=1; i<=n; i++)
    {
        sum1+=b[i];
        sum2+=c[i];

        if(sum1<0 || sum2<0) { cout<<"NO"<<endl; return; }
    }

    cout<<"YES"<<endl;

    for(int i=1; i<=n; i++)
    {
        if(b[i]==1) cout<<"(";
        else cout<<")";
    }
    cout<<endl;

    for(int i=1; i<=n; i++)
    {
        if(c[i]==1) cout<<"(";
        else cout<<")";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}