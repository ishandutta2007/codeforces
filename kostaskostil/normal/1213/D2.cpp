#include <bits/stdc++.h>

#define int long long
#define fi first
#define se second
#define pb push_back

using namespace std;

int n, k;
vector<int> v[200500];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n>>k;
    for (int x, i=1; i<=n; i++)
    {
        int t=0;
        cin>>x;
        while (x>0)
            v[x].pb(t), x/=2, t++;
    }
    int ans=1e18;
    for (int i=1; i<200500; i++)
        if (v[i].size()>=k)
    {
        int s=0;
        sort(v[i].begin(), v[i].end());
        for (int j=0; j<k; j++)
            s+=v[i][j];
        ans=min(ans, s);
    }
    cout<<ans<<"\n";
    return 0;
}