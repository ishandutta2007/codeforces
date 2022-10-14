#include <bits/stdc++.h>
#define se second
#define fi first
using namespace std;
typedef long long ll;

ll N,k = 1;
vector<pair<long long,ll>> v;
map<ll,ll> m;
ll fenwick[200050];
ll f[200050];
void update(ll pos, ll val){
    for(; pos<200050; pos += pos&-pos)fenwick[pos]+=val;
}
void u(ll pos, ll v){
    for(; pos<200050; pos+= pos&-pos)f[pos]+=v;
}
ll query (ll pos){
    ll res = 0;
    for(; pos > 0; pos -= pos&-pos)res+=fenwick[pos];
    return res;
}
ll q (ll pos){
    ll res = 0;
    for(; pos > 0; pos -= pos&-pos)res+=f[pos];
    return res;
}

int main(){
    cin >> N;
    v.resize(N);
    set<ll> s;
    for(ll i = 0; i < N; i++) scanf("%lld", &v[i].fi);
    for(ll i = 0; i < N; i++) {scanf("%lld", &v[i].se); s.insert(v[i].se);}
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(auto x: s)m[x]=k++;
    //for(auto x: v)x.se = m[x.se];
    for(ll i = 0; i < N; i++)v[i].se = m[v[i].se];
    ll re = 0;
    for (auto x: v)update(x.se, x.fi);
    for (auto x: v)u(x.se, 1);
    for (auto x: v){
        re -= query(x.se)-x.fi*(ll)q(x.se);
        update(x.se, -x.fi);
        u(x.se,-1);
    }
    cout << re << "\n";
    return 0;
}