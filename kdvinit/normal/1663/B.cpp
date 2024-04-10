/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n; cin>>n;
    int a[9] = {1200,1400,1600,1900,2100,2300,2400,2600,3000};
    for(int i=0; i<9; i++) if(a[i]>n) { cout<<a[i]<<endl; break; }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}