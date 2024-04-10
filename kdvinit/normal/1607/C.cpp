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

    priority_queue<int> pq;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        pq.push(-x);
    }

    int ans = -pq.top();

    int del=0;
    while(1)
    {
        int x = -pq.top();
        x+=del;
        ans = max(ans, x);

        if(pq.size()==1) break;
        pq.pop();

        del-=x;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}