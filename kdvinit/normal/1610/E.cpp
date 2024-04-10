/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);

    map<int, int> cnt;
    set<int> st;
    int mx = 0;

    for(int i=1; i<=n; i++)
    {
        cnt[a[i]]++;
        st.insert(a[i]);
        mx=max(mx, a[i]);
    }

    int ans = 0;
    for(int x: st)
    {
        int tmp = cnt[x];
        int d1 = cnt[x+1]; if(d1>2) d1=2;
        tmp += d1;
        int dif=1;
        while(1)
        {
            dif*=2;
            int y = x+dif;
            if(y>mx) break;
            int z = *st.lower_bound(y);
            tmp++;
            dif = (z-x);
        }
        ans = max(ans, tmp);
    }

    ans = n-ans;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}