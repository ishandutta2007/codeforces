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
ll anst = 0;
ll ansnum = -1;
ll h[105000], m[105000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, H, M, K;
    cin >> N >> H >> M >> K;
    map<ll, ll> mp;
    for(int i = 0; i < N; i++) {
        cin >> h[i] >> m[i];
        m[i] %= M / 2;
        ll t = m[i] + 1;
        ll s = m[i] + K - M / 2;
        for(int j = -1; j <= 2; j++) {
            mp[s+j*(M/2)]++;
            mp[t+j*(M/2)]--;
        }
    }
    ll now = 0;
    for(auto tmp : mp) {
        now += tmp.second;
        //cerr << tmp.first << " " << now << endl;
        if(chmax(ansnum, now)) {
            anst = tmp.first;
        }
    }
    anst %= (M / 2);
    anst += M / 2;
    anst %= M / 2;
    cout << N - ansnum << " " << anst << endl;
    for(int i = 0; i < N; i++) {
        bool ok = true;
        for(int j = 0; j < 3; j++) {
            ll T = anst + (M / 2) * j;
            if(T - K < m[i] and m[i] < T) {
                ok = false;
                //cerr << i << " " << T << endl;
            }
        }
        if(!ok) cout << i + 1 << endl;
    }
    return 0;
}