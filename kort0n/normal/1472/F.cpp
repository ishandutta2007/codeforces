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
    ll N, M;
    cin >> N >> M;
    map<ll, ll> mp;
    for(int i = 0; i < M; i++) {
        ll h, w;
        cin >> h >> w;
        h--;
        mp[w] |= (1 << h);
    }
    ll Last = 0;
    ll State = 3;
    mp[N+1] = 3;
    string ans = "YES";
    for(auto tmp : mp) {
        ll idx = tmp.first;
        ll s = tmp.second;
        //cerr << Last << " " << State << " " << idx << " " << s << " " << ans << endl;
        if(State == 3) {
            State = s;
            Last = idx;
        } else {
            if(s == 3) {
                ans = "NO";
            } else {
                if((State == s) ^ ((idx - Last) % 2 == 0)) {
                    State = 3;
                    Last = idx;
                } else {
                    ans = "NO";
                }
            }
        }
    }
    if(State != 3) ans = "NO";
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}