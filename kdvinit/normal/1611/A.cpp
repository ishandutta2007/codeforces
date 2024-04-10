/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    string s; cin>>s;
    int n = s.size();

    int a[n+1];
    for(int i=1; i<=n; i++) a[i]=s[i-1]-'0';

    if(a[n]%2==0) { cout<<0<<endl; return; }
    if(a[1]%2==0) { cout<<1<<endl; return; }

    for(int i=1; i<=n; i++) if(a[i]%2==0) { cout<<2<<endl; return; }
    cout<<-1<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}