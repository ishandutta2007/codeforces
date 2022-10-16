/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int a,b;
    cin>>a>>b;

    string s;
    cin>>s;

    int n=s.size();

    int pos=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') { pos=1; break; }
    }
    if(pos==0) { cout<<0<<endl; return; }

    int strt=0,nd=n-1;
    while(s[strt]=='0') strt++;
    while(s[nd]=='0') nd--;

    int lst=1,cnt=0,ans=a;
    for(int i=strt+1;i<=nd;i++)
    {
        if(s[i]=='1')
        {
            if(lst==0)
            {
                lst=1;
                ans+=min(b*cnt,a);
                cnt=0;
            }
        }
        else
        {
            lst=0;
            cnt++;
        }
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}