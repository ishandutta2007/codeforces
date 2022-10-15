/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int just_after(set<int>& st, int x)
{
    auto itr = st.find(x);
    itr++;
    return *itr;
}

int just_before(set<int>& st, int x)
{
    auto itr = st.find(x);
    itr--;
    return *itr;
}

void solve()
{
    int n;
    cin>>n;

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    set<int> values;
    values.insert(1e10);
    values.insert(-1e10);
    values.insert(a[1]);

    int cur=a[1];
    for(int i=2; i<=n; i++)
    {
        int l = just_before(values, cur);
        int r = just_after(values, cur);
        if(a[i]<l || a[i]>r) { cout<<"NO"<<endl; return; }
        values.insert(a[i]);
        cur=a[i];
    }
    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}