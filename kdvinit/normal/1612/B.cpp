/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, a, b;
    cin>>n>>a>>b;

    int f[n+1]={0};
    vector<int> lft;
    vector<int> rht;

    lft.push_back(a); f[a]=1;
    rht.push_back(b); f[b]=1;

    int m=n/2;
    for(int i=n; i>=a; i--)
    {
        if(lft.size()==m) break;
        if(f[i]==1) continue;
        lft.push_back(i);
        f[i]=1;
    }

    for(int i=1; i<=b; i++)
    {
        if(rht.size()==m) break;
        if(f[i]==1) continue;
        rht.push_back(i);
        f[i]=1;
    }

    if(lft.size()!=m || rht.size()!=m) { cout<<-1<<endl; return; }
    for(int x: lft) cout<<x<<" ";
    for(int x: rht) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}