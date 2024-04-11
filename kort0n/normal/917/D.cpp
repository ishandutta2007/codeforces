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
const ll mod = 1000000007;
typedef vector<vector<l_l>> VVL;
VVL dp[100];
ll N;
vector<ll> paths[100];
vector<ll> children[100];
ll inv[10000100];
ll FactorialInv[10000100];
ll Factorial[10000100];
ll beki(ll a, ll b){
    a %= mod;
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
    const int MAX = 10000002;
    Factorial[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= MAX; i++){
        Factorial[i] = Factorial[i - 1] * i % mod;
    }
    FactorialInv[MAX] = beki(Factorial[MAX], mod - 2);
    for(ll i = MAX - 1; i >= 0; i--) {
        FactorialInv[i] = FactorialInv[i+1] * (i+1) % mod;
    }
    for(int i = 1; i <= MAX; i++) {
        inv[i] = FactorialInv[i] * Factorial[i-1] % mod;
    }
}
ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}

VVL ret;

VVL merge(int a, int b) {
    //cerr << "merge: " << a << " " << b << endl;
    ret.clear();
    ret.resize(dp[a].size() + dp[b].size());
    for(int i = 0; i < dp[a].size(); i++) {
        for(int j = 0; j < dp[b].size(); j++) {
            while(ret[i+j].size() < dp[a][i].size() + dp[b][j].size() + 1) {
                ret[i+j].push_back({0, 0});
            }
            while(ret[i+j+1].size() < dp[a][i].size()) {
                ret[i+j+1].push_back({0, 0});
            }
        }
    }
    for(int i = 0; i < dp[a].size(); i++) {
        for(int j = 0; j < dp[b].size(); j++) {
            for(int k = 0; k < dp[a][i].size(); k++) {
                for(int l = 0; l < dp[b][j].size(); l++) {
                    //ll tmp = dp[a][i][k].first * dp[b][j][l].second;
                    ll tmp = dp[a][i][k].first * dp[b][j][l].first;
                    //tmp += dp[a][i][k].second * dp[b][j][l].first;
                    //tmp *= inv[2];
                    tmp %= mod;
                    ret[i+j][k+l+1].first += tmp;
                    ret[i+j][k+l+1].first %= mod;
                    tmp = dp[a][i][k].second * dp[b][j][l].second;
                    ret[i+j][k+l+1].second += tmp;
                    ret[i+j][k+l+1].second %= mod;
                    //tmp = dp[a][i][k].first * dp[b][j][l].second;
                    tmp = dp[a][i][k].first * dp[b][j][l].first;
                    tmp %= mod;
                    tmp *= N * (l + 1);
                    tmp %= mod;
                    //tmp *= inv[2];
                    //tmp %= mod;
                    ret[i+j+1][k].first += tmp;
                    ret[i+j+1][k].first %= mod;
                    tmp = dp[a][i][k].second * dp[b][j][l].second;
                    ret[i+j+1][k].second += tmp;
                    ret[i+j+1][k].second %= mod;
                }
            }
        }
    }
    for(int i = 0; i < ret.size(); i++) {
        while(!ret[i].empty() and ret[i].back().first == 0 and ret[i].back().second == 0) ret[i].pop_back();
    }
    return ret;
}

void print(VVL a) {
    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < a[i].size(); j++) {
            cout << "{" << a[i][j].first << ", " << a[i][j].second << "}" << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void dfs(int now, int from) {
    //cerr << "dfs: " << now << " " << from << endl;
    dp[now].push_back({{1, 1}});
    for(auto to : paths[now]) {
        if(from == to) continue;
        children[now].push_back(to);
        dfs(to, now);
    }
/*
    sort(children[now].begin(), children[now].end(), [](int a, int b) {
        return dp[a].size() < dp[b].size();
    });
*/
    for(auto to : children[now]) {
        //print(dp[now]);
        //print(dp[to]);
        dp[now] = merge(now, to);
        //cerr << "----" << now << "----" << to << endl;
        //print(dp[now]);
    }
    //cerr << "-----" << now << "-----" << endl;
    //print(dp[now]);
}

int main() {
    init_combination();
    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    dfs(0, -1);
    vector<ll> ans(N + 2);
    for(int i = 0; i < dp[0].size(); i++) {
        for(int j = 0; j < dp[0][i].size(); j++) {
            //cerr << i << " " << j << endl;
            ll tmp = dp[0][i][j].first;
            tmp *= N * (j + 1);
            tmp %= mod;
            ans[i+1] += tmp;
            ans[i+1] %= mod;
        }
        ans[i+1] *= inv[N] * inv[N] % mod;
        ans[i+1] %= mod;
    }
    for(int i = 1; i <= N; i++) {
        //cerr << ans[i] << " ";
        for(int j = 1; j < i; j++) {
            ll factor = combination(N-j, N-i) * ans[j] % mod;
            ans[i] += mod - factor;
        }
        ans[i] %= mod;
    }
    //cerr << endl;
    for(int i = N; i >= 1; i--) {
        if(i != N) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}