#include <bits/stdc++.h>
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
ll N, P;
vector<ll> a;

bool f(ll x) {
    ll num = 0;
    ll idx = 0;
    for(int t = 0; t < N; t++) {
        while(a[idx] <= x + t) {
            idx++;
            num++;
        }
        if(num == 0) return false;
        num--;
    }
    return true;
}

bool g(ll x) {
    ll num = 0;
    ll idx = 0;
    for(int t = 0; t < N; t++) {
        while(a[idx] <= x + t) {
            idx++;
            num++;
        }
        if(num >= P) return false;
        num--;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> P;
    a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.push_back(INF);
    ll ok1 = 1e9;
    ll ng1 = 0;
    while(abs(ok1 - ng1) > 1) {
        ll mid = (ok1 + ng1) / 2;
        if(f(mid)) ok1 = mid;
        else ng1 = mid;
    }
    ll ok2 = ok1 - 1;
    ll ng2 = 2e9;
    while(abs(ok2 - ng2) > 1) {
        ll mid = (ok2 + ng2) / 2;
        if(g(mid)) ok2 = mid;
        else ng2 = mid;
    }
    cout << ng2 - ok1 << endl;
    for(ll i = ok1; i < ng2; i++) {
        cout << i << " ";
    }
    cout << endl;
    cerr << ok1 << " " << ok2 << endl;
    return 0;
}