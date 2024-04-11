#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    while(___--)
    {
        int n, m;
        cin>>n>>m;
        vector<int> v(n);
        vector<int> cnt(m);
        for (int &i: v)
            cin>>i, cnt[i%m]++;
        int ans=0;
        for (int i=1; m-i > i; i++)
        {
            int x = cnt[i];
            int y = cnt[m-i];
            if (x+y==0)
                continue;
            ans+=max(1, abs(x-y));
        }
        if (cnt[0])
            ans++;
        if (m%2==0)
            if (cnt[m/2])
                ans++;
        cout<<ans<<"\n";
    }
}