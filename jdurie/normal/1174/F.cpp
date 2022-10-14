#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
template<class T, class S>
ostream& operator << (ostream &o, const pair<T, S> &p) {
    return o << '(' << p.first << ", " << p.second << ')';
}

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef complex<ld> pt;

#define G(x) ll x; cin >> x;
#define GD(x) ld x; cin >> x;
#define GS(s) string s; cin >> s;
#define F(i, l, r) for(ll i = l; i != r; i < r ? i++ : i--)
#define P(a) { cout << #a << ": { "; for(auto _ : a) cout << _ << " "; cout << "}" << endl; }
#define PN(a, n) { cout << #a << ": { "; F(_, 0, n) cout << a[_] << " "; cout << "}" << endl; }
#define CE(a, x) lower_bound(a.begin(), a.end(), x)
#define UP(a, x) upper_bound(a.begin(), a.end(), x)
#define FL(a, x) (x < *a.begin() ? a.end() : --UP(a, x))
#define LO(a, x) (x <= *a.begin() ? a.end() : --CE(a, x))
#define K first
#define V second
#define X real()
#define Y imag()
#define M 1000000007 //998244353
#define N 200010

vector<ll> tree[N];
ll sz[N], dep[N];
bool used[N];

void fillDep(ll i, ll p, ll d) {
    dep[i] = d;
    for(ll j : tree[i]) if(j != p) fillDep(j, i, d + 1);
}

ll getSize(ll i, ll p) {
    sz[i] = 1;
    for(ll j : tree[i])
        if(j != p && !used[j])
            sz[i] += getSize(j, i);
    return sz[i];
}

ll centroid(ll i, ll p, ll n) {
    for(ll j : tree[i])
        if(j != p && !used[j] && sz[j] > n / 2)
            return centroid(j, i, n);
    return i;
}

int main() {
    ll n, u, v;
    cin >> n;
    for(ll i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    fillDep(1, -1, 0);
    cout << "d 1" << endl;
    cout.flush();
    ll root = 1, dx;
    cin >> dx;
    while(1) {
        ll cent = centroid(root, -1, getSize(root, -1)), dist;
        cout << "d " << cent << endl;
        cout.flush();
        cin >> dist;
        if(!dist) {
            cout << "! " << cent << endl;
            return 0;
        }
        used[cent] = true;
        if(dist + dep[cent] == dx) {
            cout << "s " << cent << endl;
            cout.flush();
            cin >> root;
        }
    }
}