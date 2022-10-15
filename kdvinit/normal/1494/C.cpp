/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int INF = 1e10;

int Val(vector<int>& a, vector<int>& b)
{
    a.push_back(INF);
    b.push_back(INF+10);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    set<int> spec;
    for(int i=0; i<b.size()-1; i++) spec.insert(b[i]);

    int already = 0;
    for(int i=0; i<a.size()-1; i++)
    {
        if(spec.count(a[i])==1) already++;
    }

    int ans=already;

    int j=0;
    if(spec.count(a[j])==1) already--;

    int strt=0;
    while(strt<b.size() && b[strt]<a[0]) strt++;

    for(int i=strt; i<b.size()-1; i++)
    {
        while( (b[i]+j) >= a[j+1]  )
        {
            j++;
            if(spec.count(a[j])==1) already--;
        }
        int k = lower_bound(b.begin(), b.end(), b[i]+j+1) - b.begin();
        int tmp = already + k - i;
        ans = max(ans, tmp);
    }

    return ans;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    vector<int> ap, an;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        if(x>0) ap.push_back(x);
        else an.push_back(-x);
    }

    vector<int> bp, bn;
    for(int i=1;i<=m;i++)
    {
        int x; cin>>x;
        if(x>0) bp.push_back(x);
        else bn.push_back(-x);
    }

    int ans = Val(ap, bp) + Val(an, bn);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}