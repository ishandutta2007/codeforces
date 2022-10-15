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
    int n,k,x;
    cin>>n>>k;

    x=n%k;
    x=min(x,(k/2));
    n/=k;
    n*=k;
    n+=x;
    cout<<n<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}