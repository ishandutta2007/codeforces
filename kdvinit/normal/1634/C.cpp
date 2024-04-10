/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, k;
    cin>>n>>k;

    if(k==1)
    {
        cout<<"YES"<<endl;
        for(int i=1; i<=n; i++) cout<<i<<endl;
        return;
    }

    if(n%2==1) { cout<<"NO"<<endl; return; }

    cout<<"YES"<<endl;

    int a[n+1][k+1];

    int odd=1, even=2;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            if(i%2==1)
            {
                a[i][j]=odd;
                odd+=2;
            }
            else
            {
                a[i][j]=even;
                even+=2;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=k; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
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