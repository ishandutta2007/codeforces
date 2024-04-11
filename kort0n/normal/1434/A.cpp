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
ll a[7];
ll N;
vector<ll> b;
ll idx[6];
vector<ll> v;
ll from[7];
int main() {
    for(int i = 0; i < 6; i++) cin >> a[i];
    sort(a, a + 6);
    a[6] = 1e12;
    cin >> N;
    b.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> b[i];
        for(int j = 0; j < 6; j++) {
            v.push_back(b[i] - a[j]);
        }
    }
    sort(b.begin(), b.end());
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll ans = INF;
    for(auto under : v) {
        if(b[0] - a[0] < under) continue;
        //cerr << "---" << under << "---" << endl;
        from[0] = 0;
        for(int i = 1; i < 6; i++) {
            auto itr = lower_bound(b.begin(), b.end(), under + a[i]);
            from[i] = itr - b.begin();
        }
        from[6] = N;
        /*
        for(int i = 0; i < 6; i++) cerr << from[i] << " ";
        cerr << endl;
        */
        ll tmp = abs(b[0] - a[0]);
        for(int i = 1; i < 7; i++) {
            if(from[i] == from[i-1]) continue;
            chmax(tmp, abs(b[(from[i]-1)] - a[i-1]));
        }
        chmin(ans, tmp - under);
    }
    cout << ans << endl;
    return 0;
}