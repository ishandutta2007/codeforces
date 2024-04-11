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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, A, R, M;
    cin >> N >> A >> R >> M;
    chmin(M, A + R);
    vector<ll> h(N);
    vector<ll> v;
    for(int i = 0; i < N; i++) {
        cin >> h[i];
        v.push_back(h[i]);
    }
    sort(h.begin(), h.end());
    vector<ll> sum(N + 1);
    for(int i = 1; i <= N; i++) {
        sum[i] = sum[i-1] + h[i-1];
    }
    for(int j = -1; j <= 1; j++) {
        v.push_back(sum[N] / N + j);
    }
    ll ans = 1e18;
    for(auto target : v) {
        if(target < 0) continue;
        auto itr = lower_bound(h.begin(), h.end(), target);
        ll idx = itr - h.begin();
        ll add = idx * target - sum[idx];
        ll del = (sum[N] - sum[idx]) - (N - idx) * target;
        ll mov = min(add, del);
        add -= mov;
        del -= mov;
        ll tmp = A * add + R * del + M * mov;
        chmin(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}