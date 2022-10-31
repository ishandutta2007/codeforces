//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int DIM = 2E5+7;
int cur[DIM];
pair<int,int> vl[DIM];
int vis[DIM];
void solve(){
    int n,k;
    cin>>n>>k;
    ll res = -1E14;
    for(int i = 1;i<=n;++i){
        int x;
        cin>>x;
        if (cur[x]!=0)
            res = max(res,ll(cur[x])*i-ll(k)*x);
        cur[x] = i;
    }
    //vis[0] = 1;
    int lg = 1;
    while((1<<lg)-1<n)
        ++lg;
    int sz = (1<<lg)-1;
    for(int mask = 0;mask<=n;++mask){
        if (!cur[mask])
            continue;
        int antimask = sz^mask;
        for(int submask = antimask;submask>0;submask = (submask-1)&antimask){
            int par = sz^submask;
            vl[par].second = max(vl[par].second,cur[mask]);
            if (vl[par].first<vl[par].second)
                swap(vl[par].first,vl[par].second);
            ++vis[par];
        }
        int par = sz;
        vl[par].second = max(vl[par].second,cur[mask]);
        if (vl[par].first<vl[par].second)
            swap(vl[par].first,vl[par].second);
        ++vis[par];
    }

    for(int msk = 0;msk<=sz;++msk){
        if (vis[msk]>1)
            res = max(res,ll(ll(vl[msk].first)*vl[msk].second-ll(msk)*k));
        vis[msk] = cur[msk] = 0;
        vl[msk].first = vl[msk].second = 0;
    }
    cout<<res<<endl;
}
int main()
{
//    freopen("events.in","r",stdin);
//    freopen("events.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
/**
1
6 3
111001
111100
10 3
1101000000
1011000000

**/