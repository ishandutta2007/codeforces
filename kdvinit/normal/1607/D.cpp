/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    vector<int> lr[n+2];
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;

        if(a[i]<1)
        {
            if(x=='R') lr[1].push_back(n);
            continue;
        }
        if(a[i]>n)
        {
            if(x=='B') lr[1].push_back(n);
            continue;
        }

        if(x=='B') lr[1].push_back(a[i]);
        else lr[a[i]].push_back(n);
    }

    priority_queue<int> pq;
    for(int i=1; i<=n; i++)
    {
        for(int x: lr[i]) pq.push(-x);

        if(pq.empty()) { cout<<"NO"<<endl; return; }

        int x = -pq.top();
        pq.pop();

        if(x<i) { cout<<"NO"<<endl; return; }
    }

    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}