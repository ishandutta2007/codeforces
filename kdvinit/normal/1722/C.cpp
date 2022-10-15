/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    string s[4][n+1];

    map<string, int> mp;
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=n; j++)
        {
            string cur; cin>>cur;
            s[i][j]=cur;
            mp[cur]++;
        }
    }

    int scr[4]={0};
    for(int i=1; i<=3; i++)
    {
        for(int j=1; j<=n; j++)
        {
            string cur = s[i][j];
            if(mp[cur]==1) scr[i]+=3;
            if(mp[cur]==2) scr[i]+=1;
        }
    }

    for(int i=1; i<=3; i++) cout<<scr[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}