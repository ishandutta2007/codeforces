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
    string S, T;
    cin >> N >> S >> T;
    ll l = 0;
    ll r = N - 1;
    vector<ll> ans;
    for(int i = 0; i < N; i++) {
        int now = l;
        if(i % 2 == 1) {
            now = r;
            r--;
            if(S[now] == '0') S[now] = '1';
            else S[now] = '0';
        } else {
            l++;
        }
        if(T[i] != S[now]) ans.push_back(1);
        ans.push_back(N-i);
    }
    ans.push_back(N);
    cout << ans.size();
    for(auto tmp : ans) {
        cout << " " << tmp;
    }
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