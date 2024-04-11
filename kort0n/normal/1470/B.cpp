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
map<vector<ll>, ll> mp[2];
ll maxi[2];
vector<ll> A[1050000];
bool IsPrime[1050000];
void initialize() {
    for(ll i = 2; i <= 1e6; i++) {
        IsPrime[i] = true;
    }
    for(int i = 2; i <= 1e6; i++) {
        if(!IsPrime[i]) continue;
        for(int j = 2 * i; j <= 1e6; j += i) IsPrime[j] = false;
        for(ll j = i; j <= 1e6; j += i) {
            ll num = 0;
            ll copy = j;
            while(copy % i == 0) {
                num++;
                copy /= i;
            }
            if(num % 2 == 1) A[j].push_back(i);
        }
    }
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    mp[0].clear();
    mp[1].clear();
    maxi[0] = 0;
    maxi[1] = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        auto v = A[a[i]];
        mp[0][v]++;
    }
    for(auto tmp : mp[0]) {
        if(tmp.second % 2 == 0) {
            mp[1][{}] += tmp.second;
        } else {
            mp[1][tmp.first] += tmp.second;
        }
        chmax(maxi[0], tmp.second);
    }
    for(auto tmp : mp[1]) {
        chmax(maxi[1], tmp.second);
    }
    ll Q;
    cin >> Q;
    for(ll q = 0; q < Q; q++) {
        ll w;
        cin >> w;
        if(w == 0) cout << maxi[0] << endl;
        else cout << maxi[1] << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    initialize();
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}