/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int infy = 1e19;

void solve()
{
    int n, sum=0;
    cin>>n;

    set<int> st;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;  sum+=x;
        st.insert(x);
    }

    int m;
    cin>>m;

    while(m--)
    {
        int x, y;
        cin>>x>>y;

        int ans = infy;
        int tmp;

        auto nxt = st.lower_bound(x);
        if(nxt!=st.end())
        {
            int z = *nxt;
            tmp = y-(sum-z);
            tmp = max(tmp, (int)0);
            int ans1 = tmp;
            ans = min(ans, ans1);
        }

        if(nxt!=st.begin())
        {
            nxt--;
            int z = *nxt;
            int ans2 = x-z;
            tmp = y-(sum-z);
            tmp = max(tmp, (int)0);
            ans2+=tmp;
            ans = min(ans, ans2);
        }

        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}