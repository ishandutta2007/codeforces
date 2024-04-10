#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define all(a) begin(a), end(a)
#define K first
#define V second

int main(){
    cin.tie(0)->sync_with_stdio(0);
    G(n) G(m) ll cr = 0, lst = 0;
    while(n--) {
       G(x) cr += x;
       ll v = cr / m;
       cout << v - lst << ' ';
       lst = v;
    }
    cout << '\n';
}