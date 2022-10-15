/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

bool check(vector<int> v)
{
    int n = v.size();
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                if(v[i]<=v[j] && v[j]<=v[k]) return false;
                if(v[k]<=v[j] && v[j]<=v[i]) return false;
            }
        }
    }
    return true;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        vector<int> v;
        for(int j=i; j<=n; j++)
        {
            v.push_back(a[j]);
            if(!check(v)) break;
            ans++;
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