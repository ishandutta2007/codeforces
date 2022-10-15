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

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) { cin>>a[i]; b[i]=a[i]; }
    sort(b+1, b+n+1);

    vector<array<int, 3>> ans;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==b[i]) continue;
        int d;
        for(d=1; 1; d++)
        {
            if(a[i+d]==b[i]) break;
        }
        ans.push_back({i, n, d});

        int c[n+1];
        for(int j=1; j<=n; j++) c[j]=a[j];
        for(int j=i; j<=n; j++)
        {
            int k=(j+d);
            if(k>n) k = (k-n)+i-1;
            c[j] = a[k];
        }
        for(int j=1; j<=n; j++) a[j]=c[j];
    }

    cout<<ans.size()<<endl;
    for(auto x: ans)
    {
        cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}