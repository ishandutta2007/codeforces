/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int a, b, c, m;
    cin>>a>>b>>c>>m;

    int n = a+b+c;
    int mx = n-1-2;

    int l = max(a, b);
    l = max(l, c);

    int mn = 0;

    int n2 = (n+1)/2;
    if(l>n2)
    {
        mn = 2*(l-n2);
        if(n%2==0) mn--;
    }

    if(mn<=m && m<=mx) return true;
    else return false;
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