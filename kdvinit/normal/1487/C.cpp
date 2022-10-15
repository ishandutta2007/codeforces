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

    if(n%2==1)
    {
        int won[n+1]={0};
        int m=n/2;

        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(won[i]<m)
                {
                    cout<<1<<" ";
                    won[i]++;
                }
                else
                {
                    cout<<-1<<" ";
                    won[j]++;
                }
            }
        }
        cout<<endl;
    }
    else
    {
        int won[n+1]={0};
        int m=(n-1)/2;

        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(j==i+m+1) { cout<<0<<" "; continue; }

                if(won[i]<m)
                {
                    cout<<1<<" ";
                    won[i]++;
                }
                else
                {
                    cout<<-1<<" ";
                    won[j]++;
                }
            }
        }
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}