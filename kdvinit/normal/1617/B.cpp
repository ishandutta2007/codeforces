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

    int a, b, c=1;

    if(n%2==1)
    {
        int m = n/2;
        
        if(m%2==0)
        {
            a = m + 1;
            b = m - 1;
        }
        else
        {
            a = m+2;
            b = m-2;
        }
    }
    else
    {
        a = n/2;
        b = n/2 -  1;
    }

    cout<<a<<" "<<b<<" "<<c<<endl;  
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}