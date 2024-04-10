/*
K.D. Vinit  /,,/
Hello There : )
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

const int mod = 998244353;

inline int cil(int x, int y)
{
    int ans = (x+y-1)/y;
    return ans;
}

const int mid = 320;
const int N = 1e5 + 10;
int mp[N];

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int ans=0;
    for(int i=1; i<=n; i++)
    {
        int x = a[i];
        vector<int> pl;

        for(int i=1; i<=mid; i++)
        {
            int y = x/i;
            if(y!=0) pl.push_back(y);

            int z = cil(x, i);
            z = x/z;
            pl.push_back(z);
        }

        if(i==1)
        {
            for(int x: pl) mp[x]=0;
            continue;
        }

        long long int cur = cil(a[i-1], a[i]);
        long long int tmp = ((cur-1)*(i-1))%mod;
        int lst = a[i-1]/cur;

        int tmp2 = (tmp + mp[lst])%mod;
        ans = (ans + tmp2)%mod;

        vector<pair<int, int>> st;
        for(int lst2: pl)
        {
            cur = cil(a[i-1], lst2);
            tmp = ((cur-1)*(i-1))%mod;
            lst = a[i-1]/cur;

            tmp2 = (tmp + mp[lst])%mod;
            st.push_back({lst2, tmp2});
        }

        for(auto x: st) mp[x.first]=x.second;
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}