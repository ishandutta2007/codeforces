//ICPC Template
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> pl;

#define G(x) ll x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i < (r); ++i)
#define K first
#define V second
#define N 1000010


ll deg[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    G(n) G(m)
    while(m--) {
        G(u) G(v) deg[u]++; deg[v]++;
    }
    sort(deg + 1, deg + n + 1);
    if(deg[n - 1] == 1) cout << "star topology\n";
    else if(deg[1] == 2 && deg[n] == 2) cout << "ring topology\n";
    else if(deg[1] == 1 && deg[2] == 1 && deg[3] == 2 && deg[n] == 2) cout << "bus topology\n";
    else cout << "unknown topology\n";
}