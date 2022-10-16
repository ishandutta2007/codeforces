#include <bits/stdc++.h>
//#include <atcoder/all>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
using lll = pair<l_l, ll>;
ll N;
vector<ll> a;
vector<lll> ans;
bool ALLSAME(vector<ll> v) {
    for(int i = 1; i <= N; i++) {
        if(v[i] != v[1]) return false;
    }
    return true;
}

void f(ll i, ll j, ll x) {
    if(x == 0) return;
    //cerr << "f: " << i << " " << j << " " << x << endl;
    assert(1 <= i and i <= N);
    assert(1 <= j and j <= N);
    assert(x >= 0);
    a[i] -= x * i;
    a[j] += x * i;
    assert(a[i] >= 0);
    ans.push_back({{i, j}, x});
    return;
}
void print() {
    for(int i = 1; i <= N; i++) cerr << a[i] << " ";
    cerr << endl;
}
void g() {
    if(ALLSAME(a)) return;
    ll sum = 0;
    for(auto tmp : a) sum += tmp;
    if(sum % N != 0) return;
    ll target = sum / N;
    ll from = -1;
    ll val = 0;
    for(int i = 2; i <= N; i++) {
        if(chmax(val, a[i] / i * i)) {
            from = i;
        }
    }
    if(from != -1) {
        f(from, 1, a[from] / from);
    }
    vector<l_l> v;
    for(ll i = 2; i <= N; i++) {
        ll need = 100000 * i - a[i];
        need %= i;
        v.push_back({need, i});
    }
    sort(v.begin(), v.end());
    for(auto tmp : v) {
        ll idx = tmp.second;
        ll need = tmp.first;
        if(need <= a[1]) {
            f(1, idx, need);
            f(idx, 1, a[idx] / idx);
        }
    }
    //print();
    for(int i = 2; i <= N; i++) {
        if(a[i] < target) {
            ll need = target - a[i];
            if(a[1] >= need) {
                f(1, i, need);
            }
        }
    }
}

void solve() {
    cin >> N;
    a.resize(N + 1);
    ans.clear();
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    g();
    if(!ALLSAME(a)) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for(auto tmp : ans) {
        cout << tmp.first.first << " " << tmp.first.second << " " << tmp.second << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}