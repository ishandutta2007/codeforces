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

    vector<int> a;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        a.push_back(x);
    }

    int ans = 0;
    while(1)
    {
        if(a.size()==1) break;

        vector<int> b;

        n = a.size();
        for(int i=0; i<n; i+=2)
        {
            int dif = abs(a[i]-a[i+1]);
            if(dif!=1) { cout<<-1<<endl; return; }

            if(a[i]>a[i+1]) ans++;
            int rep = (a[i]+a[i+1]+1)/4;
            b.push_back(rep);
        }

        a=b;
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