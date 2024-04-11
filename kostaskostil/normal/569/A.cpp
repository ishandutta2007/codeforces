#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

vector<int> p, ans;

main()
{
    int t, s, q;
    cin>>t>>s>>q;
    int ans=1;

    int time=0;
    int loaded=s;

    while (true)
    {
        time+=q;
        loaded+=(q-1);
        if (time>=t)
            break;
        if (time==loaded)
        {
            time=0;
            ans++;
        }
    }
    cout<<ans<<"\n";

    return 0;
}