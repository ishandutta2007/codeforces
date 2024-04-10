/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5001;
pair<int,int> mp[N];

void solve()
{
    int n;
    cin>>n;

    int x,y;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        mp[i]={x,y};
    }
    sort(mp+1,mp+n+1);

    int ans=0;
    priority_queue <int, vector<int>, greater<int> > price;
    int extra=0;
    for(int i=n;i>0;i--)
    {
        int m=mp[i].first;

        while(i>0 && mp[i].first==m)
        {
            price.push(mp[i].second);
            i--;
        }
        i++;

        int need=m-(i-1+extra);
        if(need<=0) continue;
        while(need--)
        {
            extra++;
            ans+=price.top();
            price.pop();
        }
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