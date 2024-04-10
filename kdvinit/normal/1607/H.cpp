/*
K.D. Vinit  /,,/
Don't Stalk My Code : )
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+1], b[n+1], m[n+1];
    int aa[n+1], bb[n+1];
    for(int i=1; i<=n; i++) cin>>a[i]>>b[i]>>m[i];

    map<int, vector<array<int, 3>>> mp;
    set<int> st;

    for(int i=1; i<=n; i++)
    {
        int sum = a[i]+b[i]-m[i];
        st.insert(sum);
        int ma = min(a[i], m[i]);
        int mb = min(b[i], m[i]);
        int la = m[i]-mb;

        int mna = a[i]-ma;
        int mxa = a[i]-la;

        mp[sum].push_back({mna, -1, i});
        mp[sum].push_back({mxa, 1, i});
    }

    int ans = 0;
    int vis[n+1]={0};

    for(int sum: st)
    {
        sort(mp[sum].begin(), mp[sum].end());
        set<int> seg;

        for(auto cur: mp[sum])
        {
            int x = cur[0];
            int typ = cur[1];
            int ind = cur[2];

            if(typ==-1)
            {
                seg.insert(ind);
            }
            else
            {
                if(vis[ind]==1) continue;
                ans++;
                for(auto y: seg)
                {
                    vis[y]=1;
                    aa[y] = x;
                    bb[y] = a[y]+b[y]-m[y]-aa[y];
                }
                seg.clear();
            }
        }
    }

    cout<<ans<<endl;
    for(int i=1; i<=n; i++) cout<<a[i]-aa[i]<<" "<<b[i]-bb[i]<<endl;
    cout<<endl;
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}