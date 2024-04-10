/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, m;

int ask(int k)
{
    cout<<"? ";
    for(int i=1; i<=m; i++)
    {
        if(i==k) cout<<1;
        else cout<<0;
    }
    cout<<endl;

    int x; cin>>x;
    return x;
}

int asks(int a[])
{
    cout<<"? ";
    for(int i=1; i<=m; i++) cout<<a[i];
    cout<<endl;

    int x; cin>>x;
    return x;
}

void solve()
{
    cin>>n>>m;

    vector<array<int, 2>> ed;
    for(int i=1; i<=m; i++)
    {
        int x = ask(i);
        ed.push_back({x, i});
    }
    sort(ed.begin(), ed.end());

    int a[m+1]={0};

    int cur=0;
    for(auto e: ed)
    {
        int w = e[0];
        int i = e[1];
        a[i]=1;
        int tmp = asks(a);

        if(tmp==cur+w) cur+=w;
        else a[i]=0;
    }

    cout<<"! "<<cur<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}