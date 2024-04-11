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

ll INF = 1e18;
//const ll mod = 1000000007;

ll precalc[205000];

void solve() {
    ll N, K;
    cin >> N >> K;
    if(precalc[N] < K) {
        cout << -1 << endl;
        return;
    }
    vector<ll> ans;
    //cerr << "----------" << endl;
    while(ans.size() < N) {
        ll mini = ans.size();
        ll len = N - ans.size();
        ll nowlen = 1;
        ll num = 0;
        while(num + precalc[len - nowlen] < K) {
            num += precalc[len-nowlen];
            nowlen++;
        }
        //cerr << mini << " " << num << " " << nowlen << " " << K << endl;
        for(int j = nowlen - 1; j >= 0; j--) {
            ans.push_back(mini + j);
        }
        K -= num;
    }
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i] + 1;
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    INF++;
    precalc[0] = 1;
    precalc[1] = 1;
    for(ll i = 2; i <= 2e5; i++) {
        precalc[i] = precalc[i-1] * 2;
        chmin(precalc[i], INF);
    }
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}