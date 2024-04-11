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
        int x;
        cin>>x;
        for (int& i : v)
            i-=x;
        int s = 0;
        int s0 = 0;
        int c = 0;
        int ans = 0;
        for (int i=0; i<n; i++)
        {
            if ((c==0) || (s0+v[i] >= 0))
            {
                ans++;
                s+=v[i];
                s0 = s;
                s=min(s, 0ll);
                c++;
            }
            else
            {
                s=0;
                s0=0;
                c=0;
            }
        }
        cout<<ans<<"\n";
    }

}