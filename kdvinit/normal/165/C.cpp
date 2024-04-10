/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int k; cin>>k;
    string s; cin>>s;
    int n = s.size();

    int ans = 0, cnt=0, ans0=0;
    int pos[n+1];
    pos[0]=-1;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='1') pos[++cnt]=i;
        else ans0+=(i-pos[cnt]);
        if(cnt<k) continue;
        int x = cnt-k;
        ans += (pos[x+1]-pos[x]);
    }
    if(k==0) ans=ans0;
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}