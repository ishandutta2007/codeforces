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
    string S;
    cin >> S;
    ll N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    char now = 'z';
    vector<char> ans(N);
    while(true) {
        vector<int> idx;
        for(int i = 0; i < N; i++) {
            if(a[i] == 0) idx.push_back(i);
        }
        if(idx.empty()) break;
        while(true) {
            int num = 0;
            for(auto c : S) {
                if(c == now) num++;
            }
            if(num >= idx.size()) break;
            now--;
        }
        for(auto i : idx) {
            for(int j = 0; j < N; j++) {
                if(a[j] <= 0) continue;
                a[j] -= abs(i - j);
            }
            a[i] = -1;
            ans[i] = now;
        }
        now--;
    }
    for(auto c : ans) cout << c;
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