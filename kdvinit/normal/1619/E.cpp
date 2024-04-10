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
    sort(a+1, a+n+1);

    map<int, int> mp;
    for(int i=1; i<=n; i++) mp[a[i]]++;

    priority_queue<int> pq;

    int cost[n+1]={0}, lst=n;
    for(int i=1; i<=n; i++)
    {
        cost[i]=cost[i-1];
        int x = mp[i-1];
        if(x!=0)
        {
            x--;
            while(x--) pq.push(i-1);
        }
        else
        {
            if(pq.empty()) { lst=i-1; break; }
            int y = pq.top(); pq.pop();
            cost[i]+=(i-1-y);
        }
    }

    for(int i=0; i<=lst; i++)
    {
        int ans = cost[i]+mp[i];
        cout<<ans<<" ";
    }

    for(int i=lst+1; i<=n; i++) cout<<-1<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}