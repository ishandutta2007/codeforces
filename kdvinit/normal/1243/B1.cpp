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
    int n;
    cin>>n;

    string s,t;
    cin>>s;
    cin>>t;

    vector<int> pos;
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[i]) continue;
        pos.push_back(i);
    }
    int m=pos.size();
    if(m==0) { cout<<"Yes"<<endl; return; }
    if(m!=2) { cout<<"No"<<endl; return; }
    int x=pos[0];
    int y=pos[1];
    if(s[x]==s[y] && t[y]==t[x]) { cout<<"Yes"<<endl; return; }
    cout<<"No"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}