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
    int m = (2*n) + 1;

    int f[26]={0};
    for(int i=1; i<=m; i++)
    {
        string s; cin>>s;
        for(char x: s) f[x-'a']++;
    }

    char ans='a';
    for(int i=0; i<26; i++)
    {
        if(f[i]%2==0) continue;
        ans+=i;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}