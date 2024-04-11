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
    string S;
    cin >> S;
    vector<ll> one, zero;
    ll num = 0;
    vector<ll> ans(N);
    for(int i = 0; i < N; i++) {
        if(S[i] == '0') {
            if(zero.size()) {
                auto idx = zero.back();
                zero.pop_back();
                ans[i] = idx;
                one.push_back(idx);
            } else {
                num++;
                ans[i] = num;
                one.push_back(num);
            }
        }
        if(S[i] == '1') {
            if(one.size()) {
                auto idx = one.back();
                one.pop_back();
                ans[i] = idx;
                zero.push_back(idx);
            } else {
                num++;
                ans[i] = num;
                zero.push_back(num);
            }
        }
    }
    cout << num << endl;
    for(int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}