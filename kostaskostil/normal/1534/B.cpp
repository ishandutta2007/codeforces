#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax = 5e5 + 100;

typedef long long ll;
#define int ll

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int qqq;
    cin>>qqq;
    while (qqq--)
    {
        int n;
        cin>>n;
        vector<int> v(n + 2);
        for (int i = 1; i<=n; i++)
            cin>>v[i];
        int ans = 0;
        for (int i = 1; i<=n; i++)
            if (v[i] > v[i-1] and v[i] > v[i+1])
            {
                int s = max(v[i-1], v[i+1]);
                ans += v[i] - s;
                v[i] =s;
            }
        for (int i=1; i<=n+1; i++)
            ans += abs(v[i] - v[i-1]);
        cout<<ans<<"\n";
    }
}