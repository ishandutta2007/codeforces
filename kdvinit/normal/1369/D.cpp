/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

int mod=1000000007;
int top_yellow[2000001]={0},ans[2000001]={0};

void solve()
{
    ans[3]=4;
    top_yellow[3]=1;

    for(int i=4;i<2000001;i++)
    {
        if(top_yellow[i-1]==0 && top_yellow[i-2]==0) { ans[i]=(2*ans[i-2]+ans[i-1]+4)%mod; top_yellow[i]=1; }
        else ans[i]=(2*ans[i-2]+ans[i-1])%mod;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<ans[n]<<endl;
    }
    return 0;
}