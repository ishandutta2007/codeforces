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

    int a[n+1];
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        if(x=='(') a[i]=1;
        else a[i]=0;
    }

    int op=0, left=n;
    for(int i=1; i<=n; i++)
    {
        if(i==n) break;
        if(a[i]==1) { op++; i++; left-=2; continue; }

        int j=i+1;
        while(j<=n && a[j]==1) j++;

        if(j==n+1) break;

        op++;
        int len=j-i+1;
        left -= len;
        i=j;
    }

    cout<<op<<" "<<left<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}