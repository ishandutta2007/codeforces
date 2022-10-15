/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int cl(int x, int y)
{
    int z = (x+y-1)/y;
    return z;
}

void solve()
{
    int n, k, x;
    cin>>n>>k>>x;

    x--;
    string s, ans;
    cin>>s;

    int cnt=0;
    for(int i=n-1; i>=0; i--)
    {
        if(s[i]=='a') { ans.push_back('a'); continue; }

        cnt++;
        if(i==0 || s[i-1]=='a')
        {
            cnt = (cnt*k)+1;
            int y = x%cnt;
            x/=cnt;
            while(y--) ans.push_back('b');
            cnt=0;
        }
    }

    reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}