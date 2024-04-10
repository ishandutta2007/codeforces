/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 1e6 + 5;
int mp[N]={0};

int GCD(int x, int y)
{
    if(y==0) return x;
    else return GCD(y, x%y);
}

void solve()
{
    int n;
    cin>>n;

    int mx = -1;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        mp[x]=1;
        mx = max(mx, x);
    }

    int ans = 0;
    for(int i=1; i<=mx; i++)
    {
        if(mp[i]) continue;
        int cnt=0, g=0;

        for(int j=i; j<=mx; j+=i)
        {
            if(mp[j]==0) continue;
            cnt++;
            int y = j/i;
            g = GCD(g, y);
        }

        if(cnt>1 && g==1) ans++;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}