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
vector<ll> b[105];

void solve() {
    ll N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++) b[i].clear();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            int val;
            cin >> val;
            b[i].push_back(val);
        }
        sort(b[i].begin(), b[i].end());
    }
    ll ans = 0;
    vector<vector<ll>> V;
    for(int t = 0; t < M; t++) {
        ll m = 0;
        for(int i = 0; i < N; i++) {
            if(b[m][0] > b[i][0]) m = i;
        }
        vector<ll> ans;
        for(int i = 0; i < N; i++) {
            if(i == m) {
                ans.push_back(b[m][0]);
                continue;
            }
            ans.push_back(b[i].back());
            b[i].pop_back();
        }
        b[m].erase(b[m].begin());
        V.push_back(ans);
        /*
        for(int i = 0; i < ans.size(); i++) {
            if(i != 0) cout << " ";
            cout << ans[i];
        }
        cout << endl;
        */
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(j != 0) cout << " ";
            cout << V[j][i];
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}