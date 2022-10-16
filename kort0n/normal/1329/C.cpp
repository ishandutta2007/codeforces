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
ll a[1 << 21];
ll b[1 << 21];
bool use[1 << 21];

void solve() {
    ll g, h;
    cin >> h >> g;
    ll N = (1 << h) - 1;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        b[i] = a[i];
        use[i] = false;
    }
    for(int i = 1; i < (1 << (g)); i++) {
        b[i] = -1;
    }
    vector<l_l> v;
    for(int i = 1; i <= N; i++) {
        v.push_back({a[i], i});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        if(b[1] != -1) break;
        //cerr << "---" << i << "---" << endl;
        int now = v[i].second;
        while(now >= (1 << g)) now /= 2;
        while(b[now] != -1) now /= 2;
        //cerr << v[i].second << " " << now << endl;
        if(b[now*2] != -1 and b[now*2+1] != -1) {
            b[now] = 1;
            use[v[i].second] = true;
        }
    }
    //cerr << "A" << endl;
    vector<ll> ans;
    ll ansval = 0;
    for(int i = N; i >= 1; i--) {
        //cerr << i << endl;
        if(use[i]) ansval += a[i];
        else ans.push_back(i);
    }
    cout << ansval << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}