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
bool a[25][25];

void solve() {
    ll N;
    cin >> N;
    string S, T;
    cin >> S >> T;
    vector<int> A, B;
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            a[i][j] = false;
        }
    }
    for(int i = 0; i < N; i++) {
        if(S[i] > T[i]) {
            cout << -1 << endl;
            return;
        }
        A.push_back((int)(S[i] - 'a'));
        B.push_back((int)(T[i] - 'a'));
        if(A[i] != B[i]) {
            a[A[i]][B[i]] = true;
        }
    }
    ll ans = 0;
    for(int i = 0; i < 20; i++) {
        int to = 20;
        for(int j = 0; j < 20; j++) {
            if(a[i][j]) chmin(to, j);
        }
        if(to == 20) continue;
        ans++;
        for(int j = to + 1; j < 20; j++) {
            a[to][j] |= a[i][j];
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}