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
ll N;
ll a[7005], b[7005];
map<ll, ll> mp;
set<ll> st;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    for(int i = 1; i <= N; i++) {
        cin >> b[i];
    }
    for(int i = 1; i <= N; i++) {
        if(mp[a[i]] <= 1) continue;
        mp[a[i]] = 0;
        ll now = 0;
        for(ll j = 1; j <= N; j++) {
            if((a[i] & a[j]) == a[j]) {
                st.insert(j);
            }
        }
    }
    ll ans = 0;
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        ans += b[*itr];
    }
    cout << ans << endl;
    return 0;
}