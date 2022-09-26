#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 5e5+100;

bool try_(multiset<int> st, int xs)
{
    int n=st.size();
    int x=xs;
    vector<pair<int, int> > ans;

    for (int i=1; i<=n/2; i++)
    {
        int u = *prev(st.end());
        st.erase(st.find(u));
        int v = x-u;
        if (!st.count(v))
            return false;

        st.erase(st.find(v));
        ans.pb({u, v});

        x=u;
    }
    cout<<"YES\n"<<xs<<"\n";
    for (auto pa:ans)
        cout<<pa.fi<<" "<<pa.se<<"\n";
    return true;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ___;
    cin>>___;
    for (int _=0; _<___; _++)
    {
        int n;
        cin>>n;
        vector<int> v(2*n);

        for (int& i:v) cin>>i;

        sort(v.begin(), v.end());
        int mx = v[2*n-1];

        bool ok = false;
        for (int i: v)
            if (try_(multiset<int>(v.begin(), v.end()), mx+i))
            {
                ok=true;
                break;
            }
        if (!ok)
            cout<<"NO\n";
    }

	return 0;
}