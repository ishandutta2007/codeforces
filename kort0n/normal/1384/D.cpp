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

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int bit = 30; bit >= 0; bit--) {
        int num = 0;
        for(int i = 0; i < N; i++) {
            if(a[i] & (1 << bit)) num++;
        }
        //cerr << bit << " " << num << endl;
        if(num % 2 == 0) continue;
        if(num % 4 == 1) {
            cout << "WIN" << endl;
            return;
        }
        int rest = N - num;
        if(rest % 2 == 0) {
            cout << "LOSE" << endl;
        } else {
            cout << "WIN" << endl;
        }
        return;
    }
    cout << "DRAW" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}