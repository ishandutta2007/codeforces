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
int f(char in) {
    return in - 'a';
}
string s, t;
map<char, int> mp;
int dp[205000][30];
 
int solve() {
    //cout.precision(10);
    mp.clear();
    cin >> s >> t;
    int N = s.size();
    string S = s + s;
    for(int i = S.size() - 1; i >= 0; i--) {
        for(char a = 'a'; a <= 'z'; a++) {
            dp[i][f(a)] = mp[a];
            if(mp[a] == 0) dp[i][f(a)] = -1;
        }
        mp[S[i]] = i;
    }
    int index = 0;
    if(S[0] != t[0]) {
        index = dp[0][f(t[0])];
        if(index == -1) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = index + 1;
    for(int i = 1; i < t.size(); i++) {
        ll newindex = dp[index][f(t[i])];
        if(newindex == -1) {
            cout << -1 << endl;
            return 0;
        }
        ans += newindex - index;
        index = newindex % N;
    }
    cout << (ans + N - 1) / N << endl;
    return 0;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}