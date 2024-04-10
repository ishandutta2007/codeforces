/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    string s;
    cin>>s;

    int n = s.size();

    int ans=0;
    int last[2]={0};

    for(int i=1; i<=n; i++)
    {
        if(s[i-1]!='?')
        {
            int x = s[i-1]-'0';
            last[x^(i%2)]=i;
        }
        int len = i - min(last[0], last[1]);
        ans += len;
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