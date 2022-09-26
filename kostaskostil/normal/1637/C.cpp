#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

int ans;
vector<int> v;
set<int> st;
bool p(int i)
{
    if (v[i] < 2)
        return false;

    auto it = st.upper_bound(i);
    auto itl = st.lower_bound(i);
    bool ok = false;
    vector<int> cll;
    if (itl != st.begin())
    {
        cll.pb(*prev(itl));
        v[*prev(itl)]++, ok = true;
        st.erase(prev(itl));
    }
    if (it != st.end())
    {
        cll.pb(*it);
        v[*it]++, ok = true;
        st.erase(it);
    }
    v[i] -= 2;
    ans++;
    for (int i :cll)
        p(i);
    return ok;
}

void solve()
{
    ans = 0;
    int n;
    cin>>n;
    v.resize(n);
    for (int& i : v)
        cin>>i;
    st.clear();

    for (int i=1; i+1<n; i++)
        if (v[i]%2)
            st.insert(i);

    int s = 0;
    ans = 0;
    for (int i=1; i+1<n; i++)
    {
        while (true)
        {
            if (!p(i))
                break;
        }
        ans += v[i]/2;
        v[i]%=2;
    }
    bool ok = true;
    for (int i=1; i+1<n; i++)
        if (v[i] > 0)
            ok = false;

    if (!ok)
        cout<<-1<<"\n";
    else
        cout<<ans<<"\n";
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int _;
    cin>>_;
    while (_--)
        solve();
}