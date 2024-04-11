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
string T = "abacaba";

int f(string S) {
    int ret = 0;
    for(int i = 0; i < S.size(); i++) {
        if(S.substr(i, 7) == T) ret++;
    }
    return ret;
}

void solve() {
    int N;
    string S;
    cin >> N >> S;
    for(int i = 0; i < N; i++) {
        string A = S;
        for(int j = 0; j < N; j++) {
            if(A[j] != '?') continue;
            if(i <= j and j < i + 7) A[j] = T[j-i];
            else A[j] = 'd';
        }
        if(f(A) == 1) {
            cout << "Yes" << endl;
            cout << A << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}