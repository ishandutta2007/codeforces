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

void solve() {
    string S;
    cin >> S;
    ll ans = 0;
    for(char a = '0'; a <= '9'; a++) {
        for(char b = '0'; b <= '9'; b++) {
            ll tmp = 0;
            bool fi = true;
            for(auto c : S) {
                if(fi and c == a) {
                    tmp++;
                    fi = false;
                } else if(!fi and c == b) {
                    tmp++;
                    fi = true;
                }
            }
            if(a != b and tmp % 2 == 1) tmp--;
            chmax(ans, tmp);
        }
    }
    cout << S.size() - ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}