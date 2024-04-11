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

map<char, int> dh, dw;
typedef pair<i_i, i_i> iiii;
void solve() {
string S;
cin >> S;
int ans = S.size() * 5;
set<iiii> st;
int nowh = 0;
int noww = 0;
for(auto c : S) {
    if(st.find({{nowh, noww}, {dh[c], dw[c]}}) != st.end()) ans -= 4;
    st.insert({{nowh, noww}, {dh[c], dw[c]}});
    nowh += dh[c];
    noww += dw[c];
    st.insert({{nowh, noww}, {-dh[c], -dw[c]}});
}
cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
dh['N'] = 1;
dh['S'] = -1;
dw['E'] = 1;
dw['W'] = -1;
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}