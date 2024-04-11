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
    vector<int> ans;
    int factor = 1;
    int N;
    cin >> N;
    while(N) {
        while(N % 10 == 0) {
            N /= 10;
            factor *= 10;
        }
        ans.push_back(factor * (N % 10));
        N -= (N % 10);
    }
    cout << ans.size() << endl;
    for(auto val : ans) {
        cout << val << " ";
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