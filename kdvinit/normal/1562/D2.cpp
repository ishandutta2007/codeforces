/*
K.D. Vinit  |,,|
Hmm
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

const int N = 4e5;
int sum[N];

map<int, set<int>> mp;

int get_mid(int l, int r)
{
    if(l==r) return l;
    int tot = sum[r]+sum[l-1];
    int i = *mp[tot].lower_bound(l);
    return i;
}

void solve()
{
    int n, q, y; cin>>n>>q;
    sum[0]=0;
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        if(x=='+') y=1;
        else y=-1;
        if(i%2==0) y*=(-1);
        sum[i] = sum[i-1]+y;
    }

    mp.clear();
    for(int i=1; i<=n; i++) { int x = sum[i]+sum[i-1]; mp[x].insert(i); }

    while(q--)
    {
        int l, r; cin>>l>>r;
        int val = abs(sum[r] - sum[l-1]);
        if(val==0) { cout<<0<<endl; continue; }
        vector<int> ans;
        if(val%2==1) { int x = get_mid(l, r); ans.push_back(x); }
        else { int x = get_mid(l+1, r); ans.push_back(l); ans.push_back(x); }
        cout<<ans.size()<<endl;
        for(int x: ans) cout<<x<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}