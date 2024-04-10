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

    int f[n+1]={0};
    for(int i=1; i<=n; i++) f[a[i]]++;

    vector<int> ans;

    int i=1;
    while(1)
    {
        int cur=0;
        if(a[i]==0) cur=1;

        map<int, int> f2;
        f2[a[i]]=1;

        f[a[i]]--;
        i++;

        while(i<=n)
        {
            if(f[cur]==0) break;

            f2[a[i]]=1;
            f[a[i]]--;

            while(f2[cur]==1) cur++;
            i++;
        }

        ans.push_back(cur);
        if(i>n) break;
    }

    cout<<ans.size()<<endl;
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}