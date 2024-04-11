#include <bits/stdc++.h>
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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
vector<ll> v;
ll N;

ll f(vector<ll> v, ll idx) {
    if(v.empty()) return 0;
    if(idx == -1) return 0; 
    vector<ll> a, b;
    for(auto val : v) {
        if(val & (1LL << idx)) a.push_back(val);
        else b.push_back(val);
    }
    ll ret = 0;
    if(a.empty()) return f(b, idx - 1);
    if(b.empty()) return f(a, idx - 1);
    return min(f(a, idx - 1), f(b, idx - 1)) + (1LL << idx);
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    cout << f(v, 30) << endl;
    return 0;
}