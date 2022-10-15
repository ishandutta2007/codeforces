/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

#define yeh cout<<"YES"<<endl;
#define neh cout<<"NO"<<endl;

void solve()
{
    int x,y;
    cin>>x>>y;

    string s;
    cin>>s;

    int n=s.size();

    int cpx=0,cpy=0,cnx=0,cny=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R') cpx++;
        if(s[i]=='U') cpy++;
        if(s[i]=='L') cnx++;
        if(s[i]=='D') cny++;
    }

    if(x>=0) x=cpx-x;
    else x=x+cnx;

    if(y>=0) y=cpy-y;
    else y=y+cny;

    if(x>=0 && y>=0) yeh
    else neh


}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}