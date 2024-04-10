/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int lst = sqrt(n-1);
    int cur = lst+1;
    lst*=lst;

    int dif = n-lst;

    if(dif<=cur) cout<<dif<<" "<<cur<<endl;
    else  cout<<cur<<" "<<(2*cur - dif)<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}