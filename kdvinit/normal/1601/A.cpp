/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

void solve()
{
    int n;
    cin>>n;

    int f[31]={0};
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        for(int j=0; j<=30; j++)
        {
            if(x%2==1) f[j]++;
            x/=2;
        }
    }

    int g = 0;
    for(int i=0; i<=30; i++) g = GCD(g, f[i]);

    vector<int> ans;
    for(int i=1; i<=n; i++) if(g%i==0) ans.push_back(i);

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