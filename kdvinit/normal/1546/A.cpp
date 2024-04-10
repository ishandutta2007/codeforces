/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    vector<int> inc, dec;
    for(int i=1; i<=n; i++)
    {
        if(a[i]>=b[i])
        {
            int dif=a[i]-b[i];
            while(dif--) dec.push_back(i);
        }
        else
        {
            int dif=b[i]-a[i];
            while(dif--) inc.push_back(i);
        }
    }

    if(inc.size()!=dec.size()) { cout<<-1<<endl; return; }
    int m = inc.size();

    cout<<m<<endl;
    for(int i=0; i<m; i++) cout<<dec[i]<<" "<<inc[i]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}