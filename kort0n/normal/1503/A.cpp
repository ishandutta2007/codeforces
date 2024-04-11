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

bool ok(string S) {
    int a = 0;
    for(auto c : S) {
        if(c == '(') a++;
        else a--;
        if(a < 0) return false;
    }
    return a == 0;
}

void solve() {
    ll N;
    string S;
    cin >> N >> S;
    string A, B;
    A = string(N, '(');
    B = A;
    ll zero = 0;
    ll one = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            one++;
            continue;
        } else {
            zero++;
            if(zero % 2 == 0) A[i] = ')';
            else B[i] = ')';
        }
    }
    if(one % 2 != 0) {
        cout << "NO" << endl;
        return;
    }
    ll rest = one / 2;
    /*
    cerr << A << endl;
    cerr << B << endl;
    */
    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == '1' and rest) {
            rest--;
            A[i] = ')';
            B[i] = ')';
        }
    }
    if(ok(A) and ok(B)) {
        cout << "YES" << endl;
        cout << A << endl;
        cout << B << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}