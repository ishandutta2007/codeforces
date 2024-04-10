/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int GCD(int x, int y)
{
   if(y==0) return x;
   else return GCD(y, x%y);
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    vector<int> b;
    for(int i=1; i<=n; i++) if(a[i]%2==0) b.push_back(a[i]);
    for(int i=1; i<=n; i++) if(a[i]%2==1) b.push_back(a[i]);

    int ans=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(GCD(b[i], 2*b[j])>1) ans++;
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