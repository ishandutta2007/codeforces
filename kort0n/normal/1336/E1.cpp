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
const ll mod = 998244353;
ll N, M;
ll a[201000];
ll ans[100];
ll factor = 1;
vector<ll> v;

ll f(ll x) {
    if(x == 1) return 0;
    return 1 + f(x / 2);
}

void solve1() {
    for(int bits = 0; bits < (1 << v.size()); bits++) {
        ll XOR = 0;
        for(int i = 0; i < v.size(); i++) {
            if(bits & (1 << i)) XOR ^= v[i];
        }
        ll k = __builtin_popcountll(XOR);
        ans[k]++;
    }
}

int dp[1 << 15][38][38];

void solve2() {
    for(int i = 0; i < v.size(); i++) {
        int b = M - 1 - i;
        int l = f(v[i]);
        for(int j = 0; j < v.size(); j++) {
            ll New = v[j];
            if(v[j] & (1LL << b)) New |= (1LL << l);
            else New &= ~(1LL << l);
            if(v[j] & (1LL << l)) New |= (1LL << b);
            else New &= ~(1LL << b);
            v[j] = New;
        }
    }
    /*
    for(auto val : v) cerr << bitset<5>(val) << " ";
    cerr << endl;
    for(auto val : v) cerr << bitset<5>(val ^ (1LL << f(val))) << " ";
    cerr << endl;
    */
    dp[0][0][0] = 1;
    ll L = f(v.back());
    assert(L <= 14);
    for(int i = 0; i < v.size(); i++) {
        for(ll before = 0; before < (1LL << L); before++) {
            for(int num = 0; num <= i; num++) {
                //cerr << i << " " << num << " " << before << " " << dp[before][i][num] << endl;
                dp[before][i+1][num] += dp[before][i][num];
                dp[before][i+1][num] %= mod;
                dp[before^v[i] ^ (1LL << f(v[i]))][i+1][num+1] += dp[before][i][num];
                dp[before^v[i] ^ (1LL << f(v[i]))][i+1][num+1] %= mod;
            }
        }
    }
    for(ll val = 0; val < (1LL << L); val++) {
        for(int num = 0; num <= v.size(); num++) {
            ll k = __builtin_popcountll(val) + num;
            //cerr << val << " " << num << " " << dp[val][v.size()][num] << endl;
            ans[k] += dp[val][v.size()][num];
            ans[k] %= mod;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N; i++) {
        ll copy = a[i];
        for(auto tmp : v) {
            chmin(copy, copy ^ tmp);
        }
        if(copy == 0) continue;
        for(int j = 0; j < v.size(); j++) {
            chmin(v[j], v[j] ^ copy);
        }
        v.push_back(copy);
        sort(v.begin(), v.end(), greater<ll>());
    }
    for(int i = v.size(); i < N; i++) {
        factor = factor * 2 % mod;
    }
    if(v.size() < 23) {
    //if(false) {
        solve1();
    } else {
        solve2();
    }
    for(int i = 0; i <= M; i++) {
        ans[i] = ans[i] * factor % mod;
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}