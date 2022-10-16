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
    ll K;
    cin >> K;
    vector<ll> v(10);
    string codeforces = "codeforces";
    while(true) {
        ll tmp = 1;
        for(auto val : v) tmp *= val;
        if(tmp >= K) break;
        int idx = 0;
        for(int i = 1; i < 10; i++) {
            if(v[i-1] > v[i]) idx = i;
        }
        v[idx]++;
    }
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < v[i]; j++) {
            cout << codeforces[i];
        }
    }
    cout << endl;
    return 0;
}