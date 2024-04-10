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

    priority_queue<int> pq;

    int sum=0;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        sum+=x;
        pq.push(-x);
        if(sum<0) { sum+=pq.top(); pq.pop(); }
    }
    cout<<pq.size()<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}