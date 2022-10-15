/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s;
    cin>>s;

    int n=s.size();

    int freq[26]={0};
    for(int i=0; i<n; i++)
    {
        freq[s[i]-'a']++;
    }

    int ans=0;
    for(int i=0; i<26; i++)
    {
        int x = freq[i];
        if(x>=2) x=2;
        ans+=x;
    }
    ans/=2;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}