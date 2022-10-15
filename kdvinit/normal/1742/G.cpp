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

    set<pair<int, int>> st;
    set<int> ist;
    int a[n+1];

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        st.insert({a[i], i});
        ist.insert(i);
    }

    vector<int> ans;

    while(1)
    {
        auto cur = *st.rbegin();
        int x = cur.first;
        int j = cur.second;

        if(x==0) break;

        ans.push_back(a[j]);
        ist.erase(j);

        set<pair<int, int>> tmp;
        for(auto y: st)
        {
            int z = (y.first|x);
            z = z-x;
            tmp.insert({z, y.second});
        }

        st=tmp;
    }

    for(int i: ist) ans.push_back(a[i]);

    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}