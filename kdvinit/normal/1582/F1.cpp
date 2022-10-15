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

    int mn[1001];
    for(int i=0; i<=1000; i++) mn[i]=1000;
    mn[0]=0;

    for(int i=1; i<=n; i++)
    {
        int x = a[i];
        if(x==0) continue;
        vector<int> pos;
        for(int j=0; j<=1000; j++)
        {
            if(mn[j]>=x) continue;
            int y = j^x;
            pos.push_back(y);
        }

        for(int y: pos)
        {
            mn[y]=min(mn[y], x);
        }
    }

    vector<int> ans;
    for(int i=0; i<=1000; i++) if(mn[i]!=1000) ans.push_back(i);

    cout<<ans.size()<<endl;
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}