/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    int n,k,m;
    cin>>n>>k;

    m=n*(n-1);
    m/=2;
    k=m-k+1;
    int j=n-1;
    while(1)
    {
        k-=j;
        if(k<=0) break;
        j--;
    }
    k+=j;
    int a,b;

    b=n-j;
    a=b+k;

    for(int i=1;i<=n;i++)
    {
        if(i==a || i==b) cout<<'b';
        else cout<<'a';
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}