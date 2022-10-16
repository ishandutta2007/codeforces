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

int parent[200050];
vector<int> children[200050];
vector<int> pathes[200500];
ll N;


const ll mod = 998244353;
ll inv[1000000];
ll FactorialInv[1000000];
ll Factorial[1000000];
ll beki(ll a, ll b){
    if(b == 0){
        return 1;
    }
    ll ans = beki(a, b / 2);
    ans = ans * ans % mod;
    if(b % 2 == 1){
        ans = ans * a % mod;
    }
    return ans;
}
void init_combination(){
    inv[1] = 1;
    FactorialInv[1] = 1;
    Factorial[1] = 1;
    Factorial[0] = 1;
    FactorialInv[0] = 1;
    inv[0] = 1;
    for(int i = 2; i < 1000000; i++){
        inv[i] = beki(i, mod - 2);
        Factorial[i] = Factorial[i - 1] * i % mod;
        FactorialInv[i] = FactorialInv[i - 1] * inv[i] % mod;
    }
}
ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}
ll ans;

void dfs(ll now) {
    for(int i = 0; i < pathes[now].size(); i++) {
        int to = pathes[now][i];
        if(to == parent[now]) continue;
        parent[to] = now;
        children[now].push_back(now);
        dfs(to);
    }
    ll factor = Factorial[children[now].size() + 1];
    if(now == 1) {
        factor = Factorial[children[now].size()];
    }
    ans = ans * factor % mod;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    ans = N;
    for(int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        pathes[a].push_back(b);
        pathes[b].push_back(a);
    }
    init_combination();
    parent[1] = 0;
    dfs(1);
    cout << ans << endl;
    return 0;
}