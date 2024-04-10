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

    string s; cin>>s;
    int p=n-1;
    int c1=0;

    while(p>=0 && s[p]==')') c1++, p--;
    int c2 = n-c1;

    if(c1>c2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}