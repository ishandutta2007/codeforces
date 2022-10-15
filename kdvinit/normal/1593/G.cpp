/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    string s; cin>>s;
    int n = s.size();

    int cnt[n+1][2];
    memset(cnt, 0, sizeof(cnt));

    for(int i=1; i<=n; i++)
    {
        char x = s[i-1];
        cnt[i][0]=cnt[i-1][0];
        cnt[i][1]=cnt[i-1][1];
        if(x=='[' || x==']') continue;
        cnt[i][(i%2)]++;
    }

    int q; cin>>q;
    while(q--)
    {
        int l, r;
        cin>>l>>r;

        int o = cnt[r][1]-cnt[l-1][1];
        int e = cnt[r][0]-cnt[l-1][0];

        int ans = abs(o-e);
        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}