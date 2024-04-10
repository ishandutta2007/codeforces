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

    int a[n+3];
    int sum = 0;
    for(int i=1; i<=n+2; i++) { cin>>a[i]; sum+=a[i]; }

    sort(a+1, a+n+3);

    int x = sum - 2*a[n+2];
    for(int i=1; i<=n+2; i++)
    {
        if(i==n+2) continue;
        if(a[i]==x)
        {
            for(int j=1; j<=n+2; j++)
            {
                if(j==n+2 || j==i) continue;
                cout<<a[j]<<" ";
            }
            cout<<endl;
            return;
        }
    }

    x = sum - 2*a[n+1];
    for(int i=1; i<=n+2; i++)
    {
        if(i==n+1) continue;
        if(a[i]==x)
        {
            for(int j=1; j<=n+2; j++)
            {
                if(j==n+1 || j==i) continue;
                cout<<a[j]<<" ";
            }
            cout<<endl;
            return;
        }
    }

    cout<<-1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}