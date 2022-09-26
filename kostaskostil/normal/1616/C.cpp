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
        cin>>n;
        vector<int> v(n);
        for (int& i : v)
            cin>>i;
        if (n<=2)
        {
            cout<<0<<"\n";
            continue;
        }
        int ans = n;
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
        {
            int cur = 0;
            for (int t=0; t<n; t++)
            {
                if ((v[i]-v[t]) * (j-t) != (v[j] - v[t]) * (i-t))
                    cur++;
            }
            ans=min(ans, cur);
        }
        cout<<ans<<"\n";
        continue;
    }

}