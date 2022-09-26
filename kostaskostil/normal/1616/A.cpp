#include <bits/stdc++.h>
#define y1 y_1
#define fi first
#define se second
#define pb push_back
#define int long long
using namespace std;

const int nmax = 1000500;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    while (___--)
    {
        int n;
        map<int, int> mp;
        cin>>n;
        while (n--)
        {
            int x;
            cin>>x;
            mp[abs(x)]++;
        }
        int ans =0;
        for (auto pa : mp)
            ans+=min(pa.se, 2ll);
        if (mp[0] >= 2)
            ans--;
        cout<<ans<<"\n";
    }

}