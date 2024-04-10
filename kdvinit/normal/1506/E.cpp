/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int mnu[n+1]={0};
    int mn[n+1];

    int j=1;
    int lst=0;
    for(int i=1; i<=n; i++)
    {
        int p=a[i];
        if(p!=lst)
        {
            lst=p;
            mn[i]=p;
            mnu[p]=1;
        }
        else
        {
            while(mnu[j]==1) j++;
            mnu[j]=1;
            mn[i]=j;
        }
    }

    for(int i=1; i<=n; i++) cout<<mn[i]<<" ";
    cout<<endl;

    vector<int> Available;
    int mx[n+1];

    lst=0;
    for(int i=1; i<=n; i++)
    {
        int p=a[i];
        if(p!=lst)
        {
            mx[i]=p;
            for(int j=lst+1; j<p; j++) Available.push_back(j);
            lst=p;
        }
        else
        {
            p = Available.back();
            mx[i]=p;
            Available.pop_back();
        }
    }

    for(int i=1; i<=n; i++) cout<<mx[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}