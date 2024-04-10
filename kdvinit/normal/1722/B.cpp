/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int n;
    cin>>n;

    string s, t;
    cin>>s>>t;

    for(int i=0; i<n; i++) if(s[i]=='G') s[i]='B';
    for(int i=0; i<n; i++) if(t[i]=='G') t[i]='B';

    return (s==t);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}