/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 100;
const int mod = 998244353;
int val[N];

void solve()
{
    int n; cin>>n;
    for(int i=n; i>=1; i--) cout<<val[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int mul=81;
    val[1]=10; val[2]=180;
    for(int i=3; i<N; i++)
    {
        mul = (mul*10)%mod;
        val[i] = ((val[i-1]*10)+mul)%mod;
    }
    solve();
    return 0;
}