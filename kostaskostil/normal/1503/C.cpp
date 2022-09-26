#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax = 1e5+100;

typedef long long ll;
#define int ll

pair<int, int> a[nmax];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i].fi>>a[i].se;
    sort(a+1, a+n+1);

    int ans=0;

    int dec = a[1].fi + a[1].se;
    for (int i=1; i<=n; i++)
    {
        int deccur = a[i].fi + a[i].se;

        if (a[i].fi - dec > 0)
            ans+=a[i].fi - dec;
        dec=max(dec, deccur);
    }

    for (int i=1; i<=n; i++)
        ans+=a[i].se;
    cout<<ans<<"\n";
}