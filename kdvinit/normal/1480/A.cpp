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

    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            if(s[i]=='a') s[i]='b';
            else s[i]='a';
        }
        else
        {
            if(s[i]=='z') s[i]='y';
            else s[i]='z';
        }
    }

    cout<<s<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}