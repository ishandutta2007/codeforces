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
    vector<ll> p(N), inv(N);
    for(int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
        inv[p[i]] = i;
    }
    int num = 0;
    int checked = N;
    while(num < N) {
        int idx = inv[num];
        int tmp = idx;
        //cerr << num << " " << idx << endl;
        while(true) {
            num++;
            if(idx + 1 == checked) break;
            if(p[idx+1] != num) {
                cout << "No" << endl;
                return;
            }
            idx++;
        }
        checked = tmp;
    }
    cout << "Yes" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}