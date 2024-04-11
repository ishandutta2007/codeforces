#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
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

void solve() {
    int N, M;
    cin >> N >> M;
    vector<ll> c(N);
    for(int i = 0; i < N; i++) cin >> c[i];
    vector<vector<int>> v(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[b].push_back(a);
    }
    map<vector<int>, ll> mp;
    for(int i = 0; i < N; i++) {
        sort(v[i].begin(), v[i].end());
        if(!v[i].empty()) mp[v[i]] += c[i];
    }
    ll ans = 0;
    for(auto tmp : mp) {
        ans = __gcd(ans, tmp.second);
    }
    cout << ans << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}