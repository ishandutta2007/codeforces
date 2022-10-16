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

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    string S;
    cin >> N >> S;
    int initial = 0;
    for(auto tmp : S) {
        if(tmp == '(') initial++;
    }
    if(initial * 2 != N) {
        cout << -1 << endl;
        return 0;
    }
    int ans = 0;
    int num = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == '(') {
            num++;
        } else {
            num--;
        }
        if(num < 0) ans++;
        if(num == 0 and S[i] == '(') ans++;
    }
    cout << ans << endl;
    return 0;
}