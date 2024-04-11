#include <bits/stdc++.h>
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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    string ans = "z";
    ans[0]++;
    int ansidx = -1;
    for(int i = 1; i <= N; i++) {
        string T = S.substr(i-1, N);
        string U = S.substr(0, i - 1);
        if((N - i) % 2 == 0) reverse(U.begin(), U.end());
        T = T + U;
        if(chmin(ans, T)) {
            ansidx = i;
        }
    }
    cout << ans << endl;
    cout << ansidx << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}