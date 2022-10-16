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
bool SORTED(vector<ll> a) {
    for(int i = 1; i < a.size(); i++) {
        if(a[i-1] > a[i]) return false;
    }
    return true;
}

ll MEX(vector<ll> a) {
    a.push_back(INF);
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for(int i = 0; i < a.size(); i++) {
        if(a[i] != i) return i;
    }
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> ans;
    vector<ll> a(N);
    ll iniN = N;
    for(int i = 0; i < N; i++) cin >> a[i];
    while(!SORTED(a)) {
        ll val = MEX(a);
        cerr << endl;
        assert(0 <= val and val <= N);
        cerr << endl;
        if(val < N) {
            ans.push_back(val);
            a[val] = val;
        } else {
            assert(val == N);
            ans.push_back(N-1);
            a[N-1] = N;
            N--;
            a.pop_back();
        }
    }
    assert(ans.size() <= 2 * iniN);
    cout << ans.size() << endl;
    for(auto val : ans) {
        cout << val + 1 << " ";
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