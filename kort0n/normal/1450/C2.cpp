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

void solve() {
    ll N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    map<ll, ll> mp;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(S[i][j] == 'X') mp[(i+j)%3]++;
            if(S[i][j] == 'O') mp[(i+j+1)%3]++;
        }
    }
    ll idx = 0;
    for(int i = 1; i < 3; i++) {
        if(mp[i] < mp[idx]) idx = i;
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(S[i][j] == 'X' and (i + j) % 3 == idx) S[i][j] = 'O';
            if(S[i][j] == 'O' and (i + j + 1) % 3 == idx) S[i][j] = 'X';
        }
    }
    for(int i = 0; i < N; i++) {
        cout << S[i] << endl;
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