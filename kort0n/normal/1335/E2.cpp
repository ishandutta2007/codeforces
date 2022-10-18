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
typedef pair<l_l, ll> lll;
vector<ll> idx[201];
void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i <= 200; i++) idx[i].clear();
    for(int i = 0; i < N; i++) {
        idx[a[i]].push_back(i);
    }
    vector<lll> query;
    query.push_back({{0, N}, 0});
    for(int val = 1; val <= 200; val++) {
        int k = idx[val].size();
        for(int i = 0; (i + 1) * 2 <= idx[val].size(); i++) {
            query.push_back({{idx[val][i] + 1, idx[val][k-1-i]}, 2 * (i + 1)});
        }
    }
    int ans = 0;
    for(int val = 1; val <= 200; val++) {
        vector<ll> num(N + 1);
        for(int i = 0; i < N; i++) {
            num[i+1] = num[i] + (a[i] == val);
        }
        for(auto q : query) {
            int l = q.first.first;
            int r = q.first.second;
            int tmp = q.second;
            tmp += num[r] - num[l];
            chmax(ans, tmp);
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}