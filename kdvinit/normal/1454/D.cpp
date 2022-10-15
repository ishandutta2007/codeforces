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

    int num,k=0,tmp=n;
    for(int i=2;i*i<=n;i++)
    {
        int val=0;
        while(tmp%i==0)
        {
            val++;
            tmp/=i;
        }
        if(val==0) continue;

        if(val>k)
        {
            num=i;
            k=val;
        }
    }

    if(k==0)
    {
        cout<<1<<endl<<n<<endl;
    }
    else
    {
        cout<<k<<endl;
        for(int i=1;i<k;i++)
        {
            cout<<num<<" ";
            n/=num;
        }
        cout<<n<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}