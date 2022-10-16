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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll ans = INF;
    string S;
    cin >> S;
    ll N = S.size();
    if(N == 1) {
        cout << -1 << endl;
        return 0;
    }
    if(N == 2) {
        if(S == "25" or S == "50" or S == "75") {
            cout << 0 << endl;
        } else if(S == "52" or S == "57") {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }
    for(int i = 0; i < S.size(); i++) {
        for(int j = 0; j < S.size(); j++) {
            if(i == j) continue;
            for(int k = 0; k < S.size(); k++) {
                if(j == k) continue;
                if(i == k) continue;
                string T;
                T.push_back(S[j]);
                T.push_back(S[i]);
                if(T != "00" and T != "25" and T != "50" and T != "75") continue;
                if(S[k] == '0') continue;
                ll tmp = 0;
                tmp += N - 1 - i;
                tmp += N - 2 - j;
                tmp += k;
                if(i < j) tmp++;
                if(i < k) tmp--;
                if(j < k) tmp--;
                cerr << i << " " << j << " " << k << " " << tmp << endl;
                chmin(ans, tmp);
            }
        }
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}