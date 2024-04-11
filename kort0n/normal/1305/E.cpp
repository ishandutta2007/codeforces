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
ll N, M;
vector<ll> v;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    ll maxi = 0;
    for(ll i = 1; i <= N; i++) {
        maxi += min(i - 1, N - i);
    }
    if(maxi < M) {
        cout << -1 << endl;
        return 0;
    }
    if(N == 1) {
        cout << "1" << endl;
        return 0;
    }
    v.push_back(1);
    v.push_back(2);
    for(ll i = 2; i < N; i++) {
        if(M == 0) break;
        if(M >= i / 2) {
            v.push_back(i + 1);
            M -= i / 2;
            continue;
        }
        v.push_back(v[i-1] + v[i- M * 2]);
        M = 0;
        break;
    }
    if(v.size() != N) {
        ll delta = v.back() + 1;
        while(v.size() != N) {
            ll rest = N - v.size();
            v.push_back(1000000000 - (rest - 1) * delta);
        }
    }
    for(auto val : v) cout << val << " ";
    cout << endl;
    return 0;
}