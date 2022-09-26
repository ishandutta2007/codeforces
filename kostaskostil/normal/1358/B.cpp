#include<bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

#define int long long

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
        map<int, int> mp;
        for (int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            mp[x]++;
        }
        int ans=1;
        int sum=1;
        for (auto pa:mp)
        {
            sum+=pa.se;
            if (sum - 1 >= pa.fi)
                ans=max(ans, sum);
        }
        cout<<ans<<"\n";
    }
}