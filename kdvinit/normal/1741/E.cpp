/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    vector<int> pos[n+1];

    for(int i=1; i<=n; i++)
    {
        int x = i-a[i];
        if(x>0) pos[x].push_back(i);
    }

    int val[n+2]={0};
    val[n+1]=1;

    for(int i=n; i>=1; i--)
    {
        int j = i+a[i];
        if(j<=n && val[j+1]==1) val[i]=1;

        for(int x: pos[i]) if(val[x+1]==1) val[i]=1;
    }

    return val[1];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}