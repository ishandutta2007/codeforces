/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,a,b;
    cin>>n>>a>>b;

    char s[n+1];
    for(int i=1;i<=b;i++) s[i]=96+i;
    for(int i=b+1;i<=a;i++) s[i]=s[b];
    for(int i=a+1;i<=n;i++) s[i]=s[i-a];

    for(int i=1;i<=n;i++) cout<<s[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}