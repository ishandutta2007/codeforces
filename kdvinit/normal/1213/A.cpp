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

    int x,cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x%2==0) cnt2++;
        else cnt1++;
    }

    cout<<min(cnt1,cnt2)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}