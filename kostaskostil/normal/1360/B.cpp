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
        int n;
        cin>>n;
        vector<int> v(n);
        for (int& i:v)
            cin>>i;
        sort(v.begin(), v.end());
        int ans=1e18;
        for (int i=1; i<n; i++)
            ans=min(ans, v[i]-v[i-1]);
        cout<<ans<<
"\n";
        }
}