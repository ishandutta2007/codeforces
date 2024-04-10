/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int shrink(int x)
{
    int ans=0;
    while(x!=0)
    {
        ans+=x%10;
        x/=10;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    while(n>=10)
    {
        n = shrink(n);
    }
    cout<<n<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}