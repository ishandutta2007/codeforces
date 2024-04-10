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
    int f[10]={0};

    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        x%=10;
        f[x]++;
        if(f[x]<=3) a.push_back(x);
    }

    n = a.size();
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                int y = a[i]+a[j]+a[k];
                if(y%10==3) { cout<<"YES"<<endl; return; }
            }
        }
    }

    cout<<"NO"<<endl;
    return;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}