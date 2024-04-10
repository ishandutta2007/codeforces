/*
K.D. Vinit
*/
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define int long long

void solve()
{
    string s;
    cin>>s;

    int x,n=s.size();
    cin>>x;

    int w[n];
    for(int i=0;i<n;i++) w[i]=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1') continue;
        if(i-x>=0) w[i-x]=0;
        if(i+x<n) w[i+x]=0;
    }

    for(int i=0;i<n;i++)
    {
        if(s[i]=='0') continue;
        if(i-x<0 && i+x>=n) { cout<<-1<<endl; return; }
        if(i-x<0 && i+x<n && w[i+x]==0) { cout<<-1<<endl; return; }
        if(i-x>=0 && i+x>=n && w[i-x]==0) { cout<<-1<<endl; return; }
        if(i-x>=0 && i+x<n && w[i+x]==0 && w[i-x]==0) { cout<<-1<<endl; return; }
    }
    for(int i=0;i<n;i++) cout<<w[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}