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
const ll mod = 998244353;
int N;
vector<i_i> v;
ll Factorial[5000500];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    Factorial[0] = 1;
    for(ll i = 1; i <= 5e6; i++) {
        Factorial[i] = Factorial[i-1] * i % mod;
    }
    cin >> N;
    v.resize(N);
    for(int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());
    ll ans = 0;
    set<int> st;
    map<int, ll> mp;
    for(int i = 0; i < v.size(); i++) {
        st.insert(v[i].first);
        mp[v[i].first]++;
    }
    ll now = 1;
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        now *= Factorial[mp[*itr]];
        now %= mod;
    }
    ans += now;
    st.clear();
    mp.clear();
    for(int i = 0; i < v.size(); i++) {
        st.insert(v[i].second);
        mp[v[i].second]++;
    }
    now = 1;
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        now *= Factorial[mp[*itr]];
        now %= mod;
    }
    ans += now;
    bool ok = true;
    for(int i = 1; i < N; i++) {
        if(v[i].second < v[i-1].second) {
            //cerr << i << endl;
            ok = false;
        }
    }
    map<i_i, ll> mp2;
    set<i_i> st2;
    for(int i = 0; i < v.size(); i++) {
        st2.insert(v[i]);
        mp2[v[i]]++;
    }
    now = 1;
    for(auto itr = st2.begin(); itr != st2.end(); itr++) {
        now *= Factorial[mp2[*itr]];
        now %= mod;
    }
    if(ok) ans -= now;
    ans += mod;
    ans %= mod;
    ans = (Factorial[N] - ans + mod) % mod;
    cout << ans << endl;
    return 0;
}