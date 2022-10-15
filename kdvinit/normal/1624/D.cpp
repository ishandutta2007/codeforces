/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, k;
    cin>>n>>k;

    int f[26]={0};
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        f[x-'a']++;
    }

    int tot=0, ind=0;

    for(int i=0; i<26; i++)
    {
        tot += (f[i])/2;
        ind += (f[i])%2;
    }

    int al = tot/k;
    int ext = (tot%k)*2 + ind;

    int len = (2*al);
    if(ext>=k) len++;

    cout<<len<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}