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

    int strt=0,nd=n-1,cnt=0;
    while(strt<=nd)
    {
        if(s[strt]!=s[nd]) break;

        int x=s[strt];
        cnt=0;
        while(s[strt]==x && strt<n) { strt++; cnt++; }
        while(s[nd]==x && nd>=0) { nd--; cnt++; }

        /*
        char y=x;
        cout<<y<<" "<<cnt<<endl;
        */

        if(strt>nd)
        {
            cnt/=2;
            if(cnt<2) cout<<0<<endl;
            else cout<<cnt+1<<endl;
            return;
        }

        if(cnt<3)
        {
            cout<<0<<endl;
            return;
        }
    }

    cout<<0<<endl;
    return;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}