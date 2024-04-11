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
ll osak[20000000];
ll dp[201000][21];
void solve() {
    ll N, K;
    cin >> N >> K;
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= K; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    vector<ll> a(N);
    map<ll, vector<ll>> mp;
    for(ll i = 0; i < N; i++) {
        cin >> a[i];
        set<ll> st;
        while(a[i] != 1) {
            ll tmp = osak[a[i]];
            a[i] /= tmp;
            if(st.find(tmp) != st.end()) st.erase(tmp);
            else st.insert(tmp);
        }
        for(auto tmp : st) a[i] *= tmp;
        mp[a[i]].push_back(i);
        //cerr << a[i] << " ";
    }
    //cerr << endl;
    ll r = 0;
    set<ll> st;
    for(auto tmp : mp) {
        auto v = tmp.second;
        for(int j = 1; j < v.size(); j++) {
            st.insert(v[j]);
        }
    }
    st.insert(N);
    for(ll l = 0; l < N; l++) {
        if(l >= 1) {
            auto itr = lower_bound(mp[a[l-1]].begin(), mp[a[l-1]].end(), l-1);
            ll idx = itr - mp[a[l-1]].begin();
            if(idx + 1 < mp[a[l-1]].size()) {
                st.erase(mp[a[l-1]][idx+1]);
            }
        }
        for(ll b = 0; b <= K; b++) {
            auto itr = st.begin();
            ll newb = b;
            while(true) {
                chmin(dp[*itr][newb], dp[l][b] + 1);
                newb++;
                itr++;
                if(newb > K) break;
                if(itr == st.end()) break;
            }
        }
    }
    ll ans = INF;
    for(int k = 0; k <= K; k++) {
        chmin(ans, dp[N][k]);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 1; i <= 1e7; i++) osak[i] = i;
    for(ll i = 2; i <= 1e7; i++) {
        if(osak[i] != i) continue;
        for(ll j = 2 * i; j <= 1e7; j += i) {
            osak[j] = i;
        }
    }
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}