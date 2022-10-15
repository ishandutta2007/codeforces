/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n;

int calc(vector<int> aa, vector<int> bb)
{
    int ans=0;
    for(int i=0; i<n; i++) ans+=bb[i];

    int tmp=ans;
    for(int i=0; i<n; i++)
    {
        tmp-=bb[i];
        tmp+=aa[i];
        ans = min(ans, tmp);
    }

    return ans;
}

void solve()
{
    cin>>n;

    int a[n+1][n+1], b[n+1][n+1];

    int ans = 0;
    for(int i=1; i<=(2*n); i++)
    {
        for(int j=1; j<=(2*n); j++)
        {
            int x; cin>>x;

            if(i<=n)
            {
                if(j<=n) continue;
                else b[i][j-n]=x;
            }
            else
            {
                if(j<=n) a[i-n][j]=x;
                else ans+=x;
            }
        }
    }

    int tmp = min({a[1][1], a[1][n], a[n][1], a[n][n], b[1][1], b[1][n], b[n][1], b[n][n]});
    ans += tmp;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}