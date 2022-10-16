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
ll num[26];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, T;
    cin >> N >> T;
    string S;
    cin >> S;
    ll now = 0;
    for(int i = 0; i + 2 < S.size(); i++) {
        int d = (int)(S[i] - 'a');
        num[d]++;
    }
    now += (1 << ((int)(S[N-1] - 'a')));
    now -= (1 << ((int)(S[N-2] - 'a')));
    for(int i = 25; i >= 0; i--) {
        while(num[i]--) {
            if(now <= T) {
                now += (1 << i);
            } else {
                now -= (1 << i);
            }
        }
    }
    if(now == T) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}