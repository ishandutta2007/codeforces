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
    ll N, K;
    cin >> N >> K;
    vector<ll> c(N);
    for(int i = 0; i < N; i++) cin >> c[i];
    ll ansval = 0;
    vector<ll> ans(N);
    priority_queue<l_l> que;
    for(int timer = 0; timer < K + N; timer++) {
        if(timer < N) {
            que.push({c[timer], timer});
        }
        if(timer >= K) {
            auto tmp = que.top();
            que.pop();
            ans[tmp.second] = timer;
            ansval += tmp.first * (timer - tmp.second);
        }
    }
    cout << ansval << endl;
    for(int i = 0; i < N; i++) {
        cout << ans[i] + 1  << " ";
    }
    cout << endl;
    return 0;
}