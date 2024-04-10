/*
K.D. Vinit  |,,|
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

    int freq[41]={0},ans=0;
    for(int i=1;i<=n;i++)
    {
        int x,val=0;
        cin>>x;
        while(x>0)
        {
            val++;
            x/=2;
        }
        freq[val]++;
    }

    for(int i=1;i<=40;i++)
    {
        int cnt=( freq[i]*(freq[i]-1) )/2;
        ans+=cnt;
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