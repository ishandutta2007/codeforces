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
ll x[201000];
ll y[201000];
bool visited[5005];
vector<ll> ans;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    ans.push_back(0);
    visited[0] = true;
    ll now = 0;
    for(int i = 1; i < N; i++) {
        ll dist = -1e9;
        ll maxi = 0;
        for(int j = 0; j < N; j++) {
            if(visited[j]) continue;
            ll dx = x[now] - x[j];
            ll dy = y[now] - y[j];
            ll d = dx * dx + dy * dy;
            if(chmax(dist, d)) {
                maxi = j;
            }
        }
        visited[maxi] = true;
        ans.push_back(maxi);
        now = maxi;
    }
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << ans[i] + 1;
    }
    cout << endl;
    return 0;
}