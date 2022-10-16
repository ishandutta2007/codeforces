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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    priority_queue<ll> que;
    for(int i = 0; i <= K; i++) {
        que.push(0);
    }
    ll ans = 0;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    for(auto val : a) {
        auto tmp = que.top();
        ans += tmp;
        que.pop();
        tmp += val;
        que.push(tmp);
    }
    cout << ans << endl;
    return 0;
}