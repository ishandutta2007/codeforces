/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    string s; cin>>s;
    int n = s.size();

    int val=0;
    for(char x: s)
    {
        if(x=='B') val--;
        else val++;
        if(val<0) return false;
    }

    if(s[n-1]=='A') return false;

    return true;
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