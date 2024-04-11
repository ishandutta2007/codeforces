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

void solve() {
    ll N, L;
    cin >> N >> L;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    double ans = 0;
    double ls = 1;
    double rs = 1;
    int lnxt = 0;
    int rnxt = N - 1;
    double lpos = 0;
    double rpos = L;
    while(rnxt >= lnxt) {
        double tmp = abs(a[lnxt] - lpos) / ls;
        double tmp2 = abs(a[rnxt] - rpos) / rs;
        //cerr << tmp << " " << tmp2 << endl;
        if(tmp < tmp2) {
            ans += tmp;
            lpos += tmp * ls;
            rpos -= tmp * rs;
            ls += 1;
            lnxt++;
        } else {
            ans += tmp2;
            lpos += tmp2 * ls;
            rpos -= tmp2 * rs;
            rs += 1;
            rnxt--;
        }
    }
    ans += (rpos - lpos) / (rs + ls);
    cout << fixed << setprecision(30) << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}