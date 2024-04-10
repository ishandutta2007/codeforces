/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 100;
vector<int> in[N], out[N];
set<int> st;
vector<array<int, 2>> lr;
int pre[N];

void check(int l, int r)
{
    int cur = l-1;
    cur = *st.upper_bound(cur);

    while(cur<=r)
    {
        st.erase(cur);      pre[cur]=0;
        for(int x: out[cur+1]) if(pre[x]==0) lr.push_back({cur+1, x});
        for(int x: in[cur]) if(pre[x-1]==0) lr.push_back({x, cur});
        cur = *st.upper_bound(cur);
    }
}

void solve()
{
    int n, m;
    cin>>n>>m;

    st.clear();     lr.clear();
    for(int i=1; i<=n; i++) { in[i].clear(); out[i].clear(); }
    st.insert(n+1);

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) { int x; cin>>x; a[i]-=x; }

    pre[0]=0;
    for(int i=1; i<=n; i++)
    {
        pre[i]=pre[i-1]+a[i];
        if(pre[i]!=0) st.insert(i);
    }

    for(int i=1; i<=m; i++)
    {
        int l, r;
        cin>>l>>r;
        out[l].push_back(r);
        in[r].push_back(l);
        if(pre[r]==0 && pre[l-1]==0) lr.push_back({l, r});
    }

    while(!lr.empty())
    {
        auto cur = lr.back();
        lr.pop_back();

        int l=cur[0];
        int r=cur[1];

        check(l, r);
    }

    if(st.size()==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}