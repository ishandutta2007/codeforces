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
ll H, W, K;
typedef pair<string , int> si;
vector<si> ans;

void f(string S, ll m) {
    if(m == 0) return;
    if(K == 0) return;
    if(m == 1) {
        int len = min(K, (ll)S.size());
        ans.push_back({S.substr(0, len), 1});
        K -= len;
        return;
    }
    if(S.size() * m <= K) {
        ans.push_back({S, m});
        K -= S.size() * m;
        return;
    }
    int num = K / S.size();
    if(num != 0) ans.push_back({S, num});
    K -= S.size() * num;
    f(S, 1);
    return;
}


int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> K;
    if(4 * H * W - 2 * W - 2 * H < K) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    f("R", W-1);
    f("L", W - 1);
    for(int h = 2; h <= H; h++) {
        f("D", 1);
        f("R", W-1);
        f("UDL", W - 1);
    }
    f("U", H - 1);
    cout << ans.size() << endl;
    for(auto tmp : ans) {
        cout << tmp.second << " " << tmp.first << endl;
    }
    return 0;
}