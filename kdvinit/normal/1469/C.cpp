#include<bits/stdc++.h>
using namespace std;

#define int long long
void solve()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        
        int a[n];
        int mx[n],mn[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(i>0)
            {
                mx[i] = min(mx[i-1]+k-1,a[i]+k-1);
                mn[i] = max(a[i],mn[i-1]-k+1);
            }
            else
            {
                mx[i]=a[i];
                mn[i]=a[i];
            }
        }

        int i=1;
        for(i=1;i<n;i++)
        {
            if(mx[i]<mn[i]) break;
            if(i==n-1 && mn[i]!=a[i]) break;
        }
        
        if(i==n) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}