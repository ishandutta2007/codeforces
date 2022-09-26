#include<bits/stdc++.h>

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

    int ttt=0;
    cin>>ttt;
    for (int iii=0; iii<ttt; iii++)
    {
        int n, k;
        cin>>n>>k;
        int ans=n;
        for (int i=1; (i<=k and i*i<=n); i++)
            if (n%i==0)
        {
            ans=min(ans, n/i);
            if (n/i <= k)
                ans=min(ans, i);
        }
        cout<<ans<<"\n";
    }
}