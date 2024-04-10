/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int Pow(int a, int b)
{
    int res=1;
    while(b--) res*=a;
    return res;
}

void solve()
{
    int n;
    cin>>n;

    int a=0, b=0;
    for(int i=0; 1; i++)
    {
        if(n==0) break;
        int x = n%10; n/=10;
        int j = i/2;
        int y = pow(10, j)*x;

        if(i%2==0) a+=y;
        else b+=y;
    }

    int ans = (a+1)*(b+1) - 2;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}