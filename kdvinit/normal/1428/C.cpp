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
    string s;
    cin>>s;
    int n=s.size();

    int aleft=0,bleft=0,ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='A') aleft++;
        else
        {
            if(aleft>0) aleft--;
            else
            {
                bleft++;
            }
        }
    }

    bleft%=2;
    ans=aleft+bleft;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}