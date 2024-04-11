#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    map<pair<int, int>, int> cnt;
    map<int, int> mp;

    cin>>n;
    while (n--)
    {
        int x, y;
        cin>>x>>y;
        if (x > y)
            swap(x, y);
        mp[x]++;
        if (x != y)
        {
            mp[y]++;
            cnt[{x, y}]++;
        }
    }
    int ans = 0;
    for (auto pa : mp)
        ans += pa.se * (pa.se-1) / 2;
    for (auto pa : cnt)
        ans -= pa.se * (pa.se-1) / 2;
    cout<<ans<<"\n";
}