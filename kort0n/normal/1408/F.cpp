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
vector<l_l> ans;
ll N;
void f(ll offset, ll base) {
    for(ll delta = 1; delta < base; delta *= 2) {
        for(ll i = 0; i < base; i += 2 * delta) {
            for(ll j = i; j < i + delta; j++) {
                ans.push_back({j + offset, j + offset + delta});
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    ll base = 1;
    while(base * 2 <= N) base *= 2;
    f(0, base);
    f(N - base, base);
    cout << ans.size() << endl;
    for(auto tmp : ans) {
        cout << tmp.first + 1 << " " << tmp.second + 1 << endl;
    }
    return 0;
}