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
    int n;
    cin>>n;

    int temp=1,ans=0,cnt=1;
    while(1)
    {
        int val=( ( (temp)*(temp+1) )/2 );
        if(val>n) break;
        n-=val;
        ans++;
        cnt*=2;
        temp+=cnt;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}