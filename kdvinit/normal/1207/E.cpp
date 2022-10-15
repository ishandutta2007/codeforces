/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int odd=0, even=0;

    int n=14;
    for(int i=1; i<=n; i++)
    {
        if(i%2==1) odd+=(1<<(i-1));
        else even+=(1<<(i-1));
    }

    set<int> on, en;
    for(int i=0; i<(1<<14); i++)
    {
        on.insert((i|odd));
        en.insert((i|even));
    }

    int i=0, anso, anse;

    cout<<"? ";
    for(auto x: on)
    {
        i++;
        if(i==101) break;
        cout<<x<<" ";
    }
    cin>>anso;

    i=0;
    cout<<"? ";
    for(auto x: en)
    {
        i++;
        if(i==101) break;
        cout<<x<<" ";
    }
    cin>>anse;

    int ans = ((anso&odd)^odd) + ((anse&even)^even);
    cout<<"! "<<ans<<endl;
}

int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}