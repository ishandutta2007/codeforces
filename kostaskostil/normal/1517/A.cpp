#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

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
        int k = 2050;
        while (k * 10 <= n)
            k*=10;
        int ans=0;
        while (k >= 2050)
        {
            while (n >= k)
                n-=k, ans++;
            k/=10;
        }
        if (n>0)
            cout<<"-1\n";
        else
            cout<<ans<<"\n";
    }
}