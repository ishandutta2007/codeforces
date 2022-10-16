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
ll N, K;
string S;
string T;
vector<l_l> ans;
void f(int l, int r) {
    ans.push_back({l, r});
    for(int t = 0; ; t++) {
        int i = l + t;
        int j = r - t;
        if(i >= j) break;
        swap(S[i], S[j]);
    }
}

void print() {
    cout << ans.size() << endl;
    for(auto tmp : ans) {
        cout << tmp.first + 1 << " " << tmp.second + 1 << endl;
    }
}

void solve() {
    cin >> N >> K >> S;
    ans.clear();
    T.clear();
    for(int i = 0; i < K - 1; i++) {
        T += "()";
    }
    ll num = (S.size() - T.size()) / 2;
    T += string(num, '(');
    T += string(num, ')');
    for(int i = 0; i < N; i++) {
        if(S[i] == T[i]) continue;
        int idx = -1;
        for(int j = i + 1; j < N; j++) {
            if(S[j] == T[i]) {
                idx = j;
                break;
            }
        }
        assert(idx != -1);
        f(i, idx);
    }
    assert(S == T);
    print();
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}