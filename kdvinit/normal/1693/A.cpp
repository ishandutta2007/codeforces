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

    int a[n+1], sum=0;
    for(int i=1; i<=n; i++) { cin>>a[i]; sum+=a[i]; }

    if(sum!=0) return false;

    int j=n;
    while(j!=0 && a[j]==0) j--;

    sum=0;
    for(int i=1; i<=j; i++)
    {
        sum+=a[i];
        if(sum<0) return false;
        if(sum==0 && i!=j) return false;
    }

    return true;
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