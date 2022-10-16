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
ll N;
string S[3];
ll f(string S, char c) {
    ll ret = 0;
    for(auto tmp : S) {
        ret += (c == tmp);
    }
    return ret;
}

void g(string A, string B, char c) {
    int aidx = 0;
    int bidx = 0;
    string ans;
    while(aidx != A.size() or bidx != B.size()) {
        if(aidx == A.size()) {
            ans.push_back(B[bidx]);
            bidx++;
        } else if(bidx == B.size()) {
            ans.push_back(A[aidx]);
            aidx++;
        } else if(A[aidx] == c and B[bidx] == c) {
            ans.push_back(c);
            aidx++;
            bidx++;
        } else {
            char d = '0' + '1' - c;
            ans.push_back('0' + '1' - c);
            if(A[aidx] == d) aidx++;
            if(B[bidx] == d) bidx++;
        }
    }
    assert(ans.size() <= 3 * N);
    cout << ans << endl;
}

void solve() {
    cin >> N;
    for(int i = 0; i < 3; i++) cin >> S[i];
    for(int i = 0; i < 3; i++) {
        for(int j = i + 1; j < 3; j++) {
            for(char c = '0'; c <= '1'; c++) {
                if(f(S[i], c) >= N and f(S[j], c) >= N) {
                    g(S[i], S[j], c);
                    return;
                }
            }
        }
    }
    assert(false);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}