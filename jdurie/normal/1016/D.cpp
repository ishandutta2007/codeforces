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
    G(n) G(m)
    vector<ll> rows, cols;
    ll r1 = 0, c1 = 0;
    F(i, 0, n){
        G(x)
        rows.push_back(x);
        if(i) c1 ^= x;
    }
    F(i, 0, m){
        G(x)
        cols.push_back(x);
        if(i) r1 ^= x;
    }
    if((r1 ^ rows[0]) == (c1 ^ cols[0])){
        cout << "YES\n";
        F(i, 0, n) F(j, 0, m){
            if(i == 0 && j == 0) cout << (r1 ^ rows[0]) << " ";
            else if(i == 0) cout << cols[j] << " ";
            else if(j == 0) cout << rows[i] << " ";
            else cout << 0 << " ";
            if(j == m-1) cout << "\n";
        }
    }else cout << "NO\n";
}