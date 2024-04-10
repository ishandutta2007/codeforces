//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 100+7;
const ll MAXN = 1E18;
ll n,P[N];
vector<ll> V[2];
ll calc(ll num){
    ll res = 0;
    ll ptr = 0;
    for(auto to:V[0]){
        while(ptr<int(V[1].size()) && V[1][ptr]<=num/to+1 && V[1][ptr]*to<=num)
            ++ptr;
        res+=ptr;
    }
    return res;
}
void solve(){
    cin>>n;
    for(int i = 1;i<=n;++i)
        cin>>P[i];
    V[0].push_back(1);
    V[1].push_back(1);
    for(int c = 0;c<2;++c){
        for(int i = 1;i<=n;++i){
            if (i%2!=c)
                continue;
            for(int ps = 0;ps<V[c].size();++ps){
                ll to = V[c][ps];
                if (to<=MAXN/P[i]+1)
                    V[c].push_back(to*P[i]);
            }
        }
    }
    for(int c = 0;c<2;++c)
        sort(V[c].begin(),V[c].end());
    reverse(V[0].begin(),V[0].end());
    ll l = 1,r = 1E18;
    ll k;
    cin>>k;
    while(l!=r){
        ll tm = (l+r)/2;
        if (calc(tm)<k)
            l = tm+1;
        else r = tm;
    }
    cout<<l<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}