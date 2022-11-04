#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define ff first
#define ss second
#define vec vector
#define all(x) (x).begin(), (x).end()
#define inf 9223372036854775807
#define mod 998244353
// #define endl '\n'
// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// use merge(all(vec1), all(vec2), vec3.begin()) to merge 2 vectors, use vec3.resize(vec1.size() + vec2.size()) first
// ll pos = partition_point(all(vec), pred) - vec.begin(); bool pred(ll a){return a<3};
// print number in binary -> cout << bitset<20>(n);
ll nxt() {ll x; cin >> x; return x;}



struct node{
    ll distA, distB, distC;
    ll priceB;
    bool visA, visB, visC;
    vec<ll> n;
};

void solve(){
	ll n = nxt(), m = nxt(), a = nxt(), b = nxt(), c = nxt();
    vec<ll> prices(m);
    vec<node> nodes(n+10);
    vec<ll> cum(m+10);
    generate(all(prices), nxt);
    sort(all(prices));
    cum[0] = 0ll;
    for (ll i = 1; i <= m; ++i)
        cum[i] = prices[i-1] + cum[i-1];
    for (ll i = 0; i < m; ++i){
        ll u = nxt(), v = nxt();
        nodes[u].n.pb(v);
        nodes[v].n.pb(u);
    }
    queue<ll> q;
    q.push(a);
    nodes[a].distA = 0;
    nodes[a].visA = true;
    while (!q.empty()){
        node &nod = nodes[q.front()]; q.pop();
        for (auto &cid: nod.n){
            node &c = nodes[cid];
            if (!c.visA){
                c.visA = true;
                c.distA = nod.distA + 1;
                q.push(cid);
            }
        }
    }
    q.push(b);
    nodes[b].distB = 0;
    nodes[b].priceB = 0;
    nodes[b].visB = true;
    while (!q.empty()){
        node &nod = nodes[q.front()]; q.pop();
        for (auto &cid: nod.n){
            node &c = nodes[cid];
            if (!c.visB){
                c.visB = true;
                c.priceB = nod.priceB + prices[nod.distB];
                c.distB = nod.distB + 1;
                q.push(cid);
            }
        }
    }
    q.push(c);
    nodes[c].distC = 0;
    nodes[c].visC = true;
    while (!q.empty()){
        node &nod = nodes[q.front()]; q.pop();
        for (auto &cid: nod.n){
            node &c = nodes[cid];
            if (!c.visC){
                c.visC = true;
                c.distC = nod.distC + 1;
                q.push(cid);
            }
        }
    }
    ll mn = inf;
    // cout << "----\n";
    for (ll i = 1; i < n+1; ++i){
        node &nod = nodes[i];
        if (nod.distB + nod.distA + nod.distC > m) continue;
        ll sm = 2*nod.priceB;
        sm += cum[nod.distB + nod.distA + nod.distC] - cum[nod.distB];
        mn = min(mn, sm);
    }
    cout << mn << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.precision(10);
	cout << fixed;
	ll t = 1;
	cin >> t;
	for (ll i = 1; i < t+1; ++i){ 
		solve();
	}
}