/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int a, b;
    cin>>a>>b;

    string s; cin>>s;
    int n = s.size();

    if(a%2==1 && b%2==1)
    {
        cout<<-1<<endl;
        return;
    }

    for(int i=0; i<n; i++)
    {
        if(s[i]=='?') continue;
        if(s[n-1-i]=='?') continue;

        if(s[i]!=s[n-1-i]) { cout<<-1<<endl; return; }
    }

    for(int i=0; i<n; i++)
    {
        if(s[i]=='?') continue;
        s[n-1-i] = s[i];
    }

    for(int i=0; i<n; i++)
    {
        if(s[i]=='?') continue;
        if(s[i]=='0') a--;
        else b--;
    }

    if(a<0 || b<0) { cout<<-1<<endl; return; }

    for(int i=0; i<n; i++)
    {
        if(n%2==1 && i==(n/2)) continue;

        if(s[i]!='?') continue;

        if(a<0 || b<0) { cout<<-1<<endl; return; }

        if(a>1)
        {
            s[i]='0';
            s[n-1-i]='0';
            a-=2;
        }
        else
        {
            s[i]='1';
            s[n-1-i]='1';
            b-=2;
        }
    }

    if(a<0 || b<0) { cout<<-1<<endl; return; }

    if(s[n/2]=='?')
    {
        if(a>0) s[n/2]='0';
        else s[n/2]='1';
    }

    for(int i=0; i<n; i++) cout<<s[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}