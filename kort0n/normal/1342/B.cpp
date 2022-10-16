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

bool AllSame(string S) {
    for(auto c : S) {
        if(c != S[0]) return false;
    }
    return true;
}

void solve() {
    string T;
    cin >> T;
    if(AllSame(T)) {
        cout << T << endl;
        return;
    }
    for(int i = 0; i < T.size(); i++) {
        cout << "01";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}