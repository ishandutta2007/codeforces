#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int Last[205000];

int f(string S) {
    int ret = 0;
    for(int i = 0; i < S.size(); i++) {
        ret = ret * 2 + (S[i] - '0');
    }
    return ret;
}

void solve() {
    string S;
    cin >> S;
    Last[0] = -1;
    for(int i = 1; i < S.size(); i++) {
        if(S[i-1] == '1') Last[i] = i-1;
        else Last[i] = Last[i-1];
    }
    ll ans = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] != '1') continue;
        for(int len = 1; len <= 20; len++) {
            if(i + len > S.size()) continue;
            int L = f(S.substr(i, len));
            int LAST = i + len - 1;
            int LEFT = LAST - L + 1;
            if(LEFT < 0) continue;
            if(Last[i] < LEFT) ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}