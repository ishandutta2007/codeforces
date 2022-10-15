/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int inf=1e16;

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int se=0,so=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1) so+=a[i];
        else se+=a[i];
    }

    int tot=se+so;
    if(tot%2==1) { cout<<"NO"<<endl; return; }

    int dif=so-se;
    dif/=2;

    int val[n+1]={0},ap=1;
    for(int i=1;i<=n;i++)
    {
        val[i]=a[i]-val[i-1];
        if(val[i]<0) ap=0;
    }

    if(dif==0)
    {
        if(ap==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        return;
    }

    int mn1[n+2],mn0[n+2];
    mn1[n+1]=inf;
    mn0[n+1]=inf;

    for(int i=n;i>0;i--)
    {
        if(i%2==1)
        {
            mn1[i]=min(mn1[i+1],val[i]);
            mn0[i]=mn0[i+1];
        }
        else
        {
            mn0[i]=min(mn0[i+1],val[i]);
            mn1[i]=mn1[i+1];
        }
    }

    for(int i=1;i<n;i++)
    {
        int d;
        if(i%2==0) d=a[i+1]-a[i];
        else d=a[i]-a[i+1];

        if(d==dif && (a[i+1]-val[i-1])>=0 )
        {
            int x=mn1[i+1];
            int y=mn0[i+1];
            int f=i+1;

            if(f%2==1)
            {
                x+=2*(a[i]-a[i+1]);
                y+=2*(a[i+1]-a[i]);
            }
            else
            {
                y+=2*(a[i]-a[i+1]);
                x+=2*(a[i+1]-a[i]);
            }

            if(x>=0 && y>=0) { cout<<"YES"<<endl; return; }
        }

        if(val[i]<0) break;
    }

    cout<<"NO"<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}