#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

typedef long long ll;
#define int ll

const int nmax = 200500;

int a[nmax];
vector<int> g[nmax];
int ma[nmax];
//multiset<int> st;
int ans;

int dfs(int v, int p = -1)
{
    if (g[v].size() == 1)
    {
//        st.insert(a[v]);
        ans += a[v];
        ma[v] = a[v];
        return a[v];
    }
    int mx = 0;
    for (int i : g[v])
        if (i!=p)
    {
        mx = max(mx, dfs(i, v));
    }
    if (a[v] > mx)
    {
//        st.erase(st.find(mx));
//        st.insert(a[v]);
        ans+=a[v]-mx;
        mx = a[v];
    }
    ma[v] = mx;
    return mx;
}
#define mx ma
int dfs2(int v, int p = -1, int up = 0)
{
    vector<int> vec;
    for (int i : g[v])
        if (i != p)
            vec.pb(mx[i]);
    sort(vec.begin(), vec.end());
    int s = vec.size();
    if (s==0)
        return a[v] + max(0ll, a[v]-up);
    if (s==1)
    {
        for (int i : g[v])
            if (i!=p)
            {
                int unt = max(a[v], up);
                return dfs2(i, v, unt) + unt-up;
            }
    }

    int ans1 = max(0ll, mx[v] - max(up, vec[s-2]));

    int unt = max({up, vec[s-2], a[v]});
    int pay = unt - max(up, vec[s-2]);
    for (int i : g[v])
        if (i!=p)
            if (mx[i] == vec[s-1])
                ans1 = min(ans1, dfs2(i, v, unt) + pay);
    return ans1;

//    for (int i : g[v])
//        if (i!=p)
//            if ()
//    {
//
//    }
//    for (int i : g[v])
//        if (i!=p)
//    {
//        int mx0 = up;
//        if ((s > 0) && (mx[i] != vec[s-1]))
//        {
//            if (s > 0)
//                mx0 = max(mx0, vec[s-1]);
//        }
//        else
//        {
//            if (s > 1)
//                mx0 = max(mx0, vec[s-2]);
//        }
//
//        int ans2 = max(0ll, a[v] - mx0) dfs2(i, v, );
//        ans1 = min(ans1, ans2);
//    }
}
#undef mx

void solve()
{
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i], g[i].clear();
    for (int i=1; i<n; i++)
    {
        int x, y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }
    if (n==2)
    {
        cout<<2*max(a[1], a[2])<<"\n";
        return;
    }
    ans = 0;
//    st.clear();
    int bol;
    for (int i=1; i<=n; i++)
    {
        if (g[i].size() > 1)
        {
            dfs(i);

//            int mx1 = *prev(st.end());
//            int mx2 = *prev(prev(st.end()));
//            bol = ans + mx1 - mx2;

            ans+=dfs2(i);

            break;
        }
    }
//    int mx1 = *prev(st.end());
//    int mx2 = *prev(prev(st.end()));
//    cout<<ans+mx1-mx2<<"\n";
//    cout<<min(bol, ans)<<"\n";
    cout<<ans<<"\n";
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    int _;
//    cin>>_;
//    while (_--)
        solve();
}