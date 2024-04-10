/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

//#define int long long
#define endl "\n"

bool check(int mm)
{
    int hh = mm/60;
    mm%=60;

    int hx = hh/10;
    int hy = hh%10;

    int mx = mm/10;
    int my = mm%10;

    return (hx==my && hy==mx);
}

void solve()
{
    string s; int n;
    cin>>s>>n;

    int hh = (s[0]-'0')*10 + (s[1]-'0');
    int mm = (s[3]-'0')*10 + (s[4]-'0');

    map<int, int> vis;
    int cur = hh*60+mm;
    int ans=0;

    while(!vis[cur])
    {
        if(check(cur)) ans++;
        vis[cur]=1;
        cur+=n;
        if(cur>=1440) cur-=1440;
        continue;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}