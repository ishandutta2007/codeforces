/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

bool prime(int n)
{
    for(int i=2; i*i<=n; i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i] =  x-'0';
    }

    for(int i=1; i<=n; i++)
    {
        if(a[i]!=2 && a[i]!=3 && a[i]!=5 && a[i]!=7)
        {
            cout<<1<<endl;
            cout<<a[i]<<endl;
            return;
        }
    }

    int freq[10]={0};
    for(int i=1; i<=n; i++)
    {
        freq[a[i]]++;
        if(freq[a[i]]==2)
        {
            cout<<2<<endl;
            cout<<a[i]<<a[i]<<endl;
            return;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            int x = a[i]*10 + a[j];
            if(prime(x)) continue;
            cout<<2<<endl;
            cout<<x<<endl;
            return;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            for(int k=j+1; k<=n; k++)
            {
                int x = a[i]*100 + a[j]*10 + a[k];
                if(prime(x)) continue;
                cout<<3<<endl;
                cout<<x<<endl;
                return;
            }
        }
    }

    cout<<4<<endl;
    for(int i=1; i<=4; i++) cout<<a[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


    int t; cin>>t;
    while(t--) solve();
    return 0;
}