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
const ll mod = 1000000007;
ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ret = beki(a, b / 2);
    ret = ret * ret % mod;
    if(b & 1) ret = ret * a % mod;
    return ret;
}
 
ll inv(ll a) {
    return beki(a, mod - 2);
}
ll N;
ll dp[200500];
ll dp2[200500];
vector<ll> children[200500];
ll parent[205000];
void dfs(int now, int from) {
    dp[now] = 1;
    for(auto to : children[now]) {
        if(to == from) continue;
        dfs(to, now);
        dp[now] *= (1 + dp[to]);
        dp[now] %= mod;
    }
}
 
void f(ll now, ll factor) {
    dp2[now] = dp[now] * factor % mod;
    //ll factorproduct = factor;
    vector<ll> L(children[now].size() + 1, 1);
    vector<ll> R(children[now].size() + 1, 1);
    for(int i = 1; i < children[now].size(); i++) {
        int to = children[now][i - 1];
        L[i] = L[i-1] * (dp[to] + 1) % mod;
    }
    for(int i = R.size() - 2; i >= 0; i--) {
        int to = children[now][i];
        R[i] = R[i+1] * (dp[to] + 1) % mod;
    }
    //for(auto to: children[now]) factorproduct = factorproduct * (1 + dp[to]) % mod;
    for(int i = 0; i < children[now].size(); i++) {
        int to = children[now][i];
        //ll nowfactor = factorproduct * inv(dp[to] + 1) + 1;
        ll nowfactor = factor;
        nowfactor *= L[i];
        nowfactor %= mod;
        nowfactor *= R[i+1];
        nowfactor %= mod;
        nowfactor++;
        nowfactor %= mod;
        f(to, nowfactor);
    }
}
 
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    parent[1] = -1;
    for(int i = 2; i <= N; i++) {
        cin >> parent[i];
        children[parent[i]].push_back(i);
    }
    dfs(1, -1);
    f(1, 1);
    for(int i = 1; i <= N; i++) cout << dp2[i] << " ";
    cout << endl;
    return 0;
}