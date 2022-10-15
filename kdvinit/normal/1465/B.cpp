/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

bool check(int n)
{
    int x = n;
    while(x!=0)
    {
        int y = x%10;
        if(y!=0 && n%y!=0) return false;
        x/=10;
    }
    return true;
}

void solve()
{
    int n;
    cin>>n;

    while(!check(n)) n++;
    cout<<n<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}