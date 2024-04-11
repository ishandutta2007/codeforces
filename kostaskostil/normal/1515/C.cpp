#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

unordered_set<int> st;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=1; i*i<=1e9; i++)
        st.insert(2*i*i), st.insert(4*i*i);

    int ___;
    cin>>___;
    while (___--)
    {
        int n, m, x;
        cin>>n>>m>>x;
        vector<pair<int, int> > h(n);
        int i = 1;
        for (auto& pa : h)
            cin>>pa.fi, pa.se = i++;
        sort(h.begin(), h.end());
        reverse(h.begin(), h.end());
        vector<int> ans(n);
        set<pair<int, int> > hs;
        for (int i=0; i<m; i++)
            hs.insert({0, i});
        for (auto pa : h)
        {
            auto pax = *hs.begin();
            hs.erase(pax);

            ans[pa.se-1] = pax.se+1;
            pax.fi += pa.fi;

            hs.insert(pax);

        }
        cout<<"YES\n";
        for (int i=0; i<n; i++)
            cout<<ans[i]<<" ";
        cout<<"\n";


    }
}