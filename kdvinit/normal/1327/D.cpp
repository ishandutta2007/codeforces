/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

const int N = 2e5 + 10;
int a[N], c[N];

int get_ans(vector<int>& b)
{
    int n = b.size();
    vector<int> fact;

    for(int i=1; i*i<=n; i++)
    {
        if(n%i) continue;
        fact.push_back(i);
        fact.push_back(n/i);
    }
    sort(fact.begin(), fact.end());

    for(int x: fact)
    {
        for(int i=0; i<x; i++)
        {
            int col = c[b[i]], pos=1;
            for(int j=i+x; j<n; j+=x) if(c[b[j]]!=col) { pos=0; break; }
            if(pos) return x;
        }
    }
}

void solve()
{
    int n; cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>c[i];

    int vis[n+1]={0};
    int ans = n;
    for(int i=1; i<=n; i++)
    {
        if(vis[i]) continue;
        vector<int> b;

        int j=i;
        while(1)
        {
            b.push_back(j); vis[j]=1; j=a[j];
            if(j==i) break;
        }

        int tmp = get_ans(b);
        ans = min(ans, tmp);
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