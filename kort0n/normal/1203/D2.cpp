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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll Left[205000], Right[205000];
string t, s;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    s = "#" + s + "#";
    t = "#" + t + "#";
    int now = 1;
    Left[0] = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == t[now]) {
            Left[now] = i;
            //cerr << now << " " << i << endl;
            now++;
        }
        if(now > m) break;
    }
    now = m;
    Right[m+1] = n + 1;
    for(int i = n; i >= 1; i--) {
        if(s[i] == t[now]) {
            //cerr << now << " " << i << endl;
            Right[now] = i;
            now--;
        }
        if(now == 0) break;
    }
    ll ans = 0;
    for(int i = 0; i <= m; i++) {
        chmax(ans,  Right[i+1] - Left[i] - 1);
    }
    cout << ans << endl;
    return 0;
}