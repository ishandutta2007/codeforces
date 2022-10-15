/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

vector<int> st, ht;

int val(int k)
{
    int lst = st.back();
    if(k>=lst) return ht.back();

    if(k<st[0]) return 0;

    int j = upper_bound(st.begin(), st.end(), k) - st.begin();
    return ht[j-1];
}

void solve()
{
    int n, q;
    cin>>n>>q;

    st.clear();
    ht.clear();

    int mx = 0;
    int sum=0;

    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        sum+=x;
        mx = max(mx, x);
        st.push_back(mx);
        ht.push_back(sum);
    }

    while(q--)
    {
        int k; cin>>k;
        cout<<val(k)<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}