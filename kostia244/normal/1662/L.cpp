#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

const int N=2e5+100,INF=2e9;

int lis(vector<int> a) {
    vector<int> b;
    for(auto &i : a) {
        auto it = upper_bound(b.begin(),b.end(), i);
        if(it == b.end()) b.push_back(i);
        else *it = i;
    }
    return b.size();
}

int t[N],a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,v;
    cin>>n>>v;
    for(int i=1;i<=n;i++)
        cin>>t[i],
        t[i]*=v;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    vector<pair<int,int>> p;
    for(int i=1;i<=n;i++)
        if(abs(a[i])<=t[i])
            p.push_back({t[i]-a[i],t[i]+a[i]});
    sort(p.begin(),p.end());
    vector<int> q;
    for(auto[i,j]:p)
        q.push_back(j);
    cout<<lis(q);
}