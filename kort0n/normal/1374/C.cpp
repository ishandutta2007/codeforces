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
    int n;
    cin >> n;
    cin >> S;
    int ans = 0;
    while(true) {
        int idx = -1;
        int sum = 0;
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '(') sum++;
            else sum--;
            if(sum < 0) {
                idx = i;
                break;
            }
        }
        if(idx == -1) break;
        ans++;
        S.erase(S.begin() + idx);
        S.push_back(')');
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int  t;
    cin >> t;
    while(t--) solve();
    return 0;
}