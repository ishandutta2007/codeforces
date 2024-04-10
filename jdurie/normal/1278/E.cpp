#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
const ll NN = 500050;

vector<ll> tree[NN];
ll sz[NN], L[NN], R[NN];

ll getSz(ll i, ll p) {
    sz[i] = 1;
    for(ll j : tree[i]) if(j != p) sz[i] += getSz(j, i);
    return sz[i];
}

void write_answers(ll i, ll p, ll st, ll rt) {
    rt += tree[i].size() - (i - 1 ? 1 : 0);
    L[i] = st; R[i] = rt;
    ll chSt = rt - 1, chEnd = rt + 1;
    for(ll j : tree[i])
        if(j != p) {
            write_answers(j, i, chSt--, chEnd);
            chEnd += 2 * sz[j] - 1;
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin >> n;
    for(ll i = 0; i < n - 1; i++) {
        ll u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    getSz(1, 0);
    write_answers(1, 0, 1, 2);
    for(ll i = 1; i <= n; i++)
        cout << L[i] << " " << R[i] << endl;
}