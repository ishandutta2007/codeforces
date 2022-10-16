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
    for(int i=1;i<=n;i++) cin>>a[i];

    int last[n+1]={0};
    vector<int> payoff;

    int q;
    cin>>q;
    while(q--)
    {
        int op;
        cin>>op;

        if(op==1)
        {
            int p,x;
            cin>>p>>x;
            a[p]=x;
            last[p]=payoff.size();
        }
        else
        {
            int x;
            cin>>x;
            payoff.push_back(x);
        }
    }

    int m=payoff.size();
    for(int i=m-2;i>=0;i--)
    {
        payoff[i]=max(payoff[i],payoff[i+1]);
    }

    for(int i=1;i<=n;i++)
    {
        if(last[i]==payoff.size()) continue;
        int x=payoff[last[i]];
        a[i]=max(a[i],x);
    }

    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}