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

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N);
    ll sum = 0;
    ll summax = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
        chmax(summax, sum);
    }
    vector<ll> b(M);
    for(int i = 0; i < M; i++) {
        cin >> b[i];
    }
    vector<ll> ans(M);
    vector<l_l> v;
    for(int i = 0; i < M; i++) {
        if(summax < b[i] and sum <= 0) {
            ans[i] = -1;
        } else {
            ll delta = b[i] - summax;
            chmax(delta, 0LL);
            ll d = 0;
            if(sum >= 1) d = (delta + sum - 1) / sum;
            ans[i] += N * d;
            v.push_back({b[i] - d * sum, i});
        }
    }
    sort(v.begin(), v.end());
    ll now = 0;
    ll idx = 0;
    for(int i = 0; i < N; i++) {
        now += a[i];
        while(idx < v.size() and v[idx].first <= now) {
            ans[v[idx].second] += i;
            idx++;
        }
    }
    for(int i = 0; i < M; i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}