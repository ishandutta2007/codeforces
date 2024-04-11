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
    ll N;
    cin >> N;
    vector<ll> a(N);
    vector<ll> idx(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&](ll q, ll w){
        return a[q] < a[w];
    });
    vector<ll> ans;
    ll sum = 0;
    for(auto i : idx) {
        if(a[i] > sum) {
            ans.clear();
        }
        sum += a[i];
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(auto val : ans) cout << val + 1 << " ";
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