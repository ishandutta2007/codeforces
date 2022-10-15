/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin>>n>>k;

    int freq[n+1]={0};
    vector<int> adj[n+1];
    int a[n+1];

    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        a[i]=x;
        freq[x]++;
        adj[x].push_back(i);
    }

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        int x = freq[i];
        if(x>k) x=k;
        ans+=x;
    }
    ans/=k;

    int col[n+1]={0};
    int tot = k*ans;
    int cnt=0;

    for(int i=1; i<=n; i++)
    {
        int cur=0;
        if(cnt==tot) break;
        for(int x: adj[i])
        {
            col[x]=(cnt%k)+1;
            cnt++;
            if(cnt==tot) break;
            cur++;
            if(cur==k) break;
        }
        if(cnt==tot) break;
    }

    for(int i=1; i<=n; i++) cout<<col[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}