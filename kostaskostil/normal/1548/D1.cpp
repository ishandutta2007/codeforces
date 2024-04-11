#include <bits/stdc++.h>
#pragma GCC optimize("O3")

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

int x[2][2];
int cnk(int n, int k)
{
    if (k > n)
        return 0;
    int ans=1;
    for (int i=0; i<k; i++)
        ans*=n-i;
    return ans;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;

    cin>>n;
    for (int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;

        x[(a/2)%2][(b/2)%2]++;
    }
    int ans=0;
    for (int xa=0; xa<2; xa++)
    for (int ya=0; ya<2; ya++)
    for (int xb=0; xb<2; xb++)
    for (int yb=0; yb<2; yb++)
    for (int xc=0; xc<2; xc++)
    for (int yc=0; yc<2; yc++)
    {
        if (( xa*(yb-yc) + xb*(yc-ya) + xc*(ya-yb))%2 == 0)
        {
            map<pair<int, int>, int> mp;
            mp[{xa, ya}]++;
            mp[{xb, yb}]++;
            mp[{xc, yc}]++;
            int d = 1;
            for (auto pa : mp)
            {
//                cout<<x[pa.fi.fi][pa.fi.se]<<" "<<pa.se<<" "<<cnk(x[pa.fi.fi][pa.fi.se], pa.se)<<"\n";
                d*=cnk(x[pa.fi.fi][pa.fi.se], pa.se);
            }
            ans+=d;
        }
    }
    cout<<ans/6<<"\n";
}