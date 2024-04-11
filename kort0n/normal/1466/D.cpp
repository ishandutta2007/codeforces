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
ll N;
ll w[201000];
ll d[210000];
void solve() {
    cin >> N;
    ll wsum = 0;
    for(int i = 0; i < N; i++) {
        cin >> w[i];
        d[i] = 0;
        wsum += w[i];
    }
    for(int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        d[a]++;
        d[b]++;
    }
    vector<ll> v;
    for(int i = 0; i < N; i++) {
        for(int j = 1; j < d[i]; j++) {
            v.push_back(w[i]);
        }
    }
    sort(v.begin(), v.end(), greater<ll>());
    cout << wsum;
    for(int i = 0; i < v.size(); i++) {
        wsum += v[i];
        cout << " " << wsum;
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