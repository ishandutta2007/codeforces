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
bool AllL(string S) {
    for(auto c : S) {
        if(c != 'L') return false;
    }
    return true;
}

void solve() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    if(AllL(S)) {
        chmin(K, N);
        if(K != 0) cout << 2 * K - 1 << endl;
        else cout << 0 << endl;
        return;
    }
    ll ans = 0;
    vector<ll> three;
    vector<ll> two;
    bool First = true;
    ll now = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'L') {
            now++;
            continue;
        } else {
            if(i == 0 or S[i-1] == 'L') ans++;
            else ans += 2;
            if(now >= 1) {
                if(First) two.push_back(now);
                else three.push_back(now);
            }
            now = 0;
            First = false;
        }
    }
    if(now) two.push_back(now);
    sort(three.begin(), three.end());
    sort(two.begin(), two.end());
    for(auto tmp : three) {
        ll num = min(tmp, K);
        ans += 2 * num;
        K -= num;
        if(num == tmp) ans++;
    }
    for(auto tmp : two) {
        ll num = min(tmp, K);
        ans += 2 * num;
        K -= num;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}