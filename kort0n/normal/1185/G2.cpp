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

ll dp[55][55][55][4];
ll num[55][55][55];
ll N, T;
ll napsack[55][2600][4];
ll ans = 0;
struct query {
    ll num;
    ll factor;
    ll val;
    query(ll _num, ll _factor, ll _val) {
        num = _num;
        factor = _factor;
        val = _val;
    }
};

bool operator< (query a, query b) {
    return a.val < b.val;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> T;
    init_combination();
    dp[1][0][0][1] = 1;
    dp[0][1][0][2] = 1;
    dp[0][0][1][3] = 1;
    for(int a = 0; a <= 50; a++) {
        for(int b = 0; b <= 50; b++) {
            for(int c = 0; c <= 50; c++) {
                for(int i = 1; i <= 3; i++) {
                    dp[a][b][c][i] %= mod;
                    num[a][b][c] += dp[a][b][c][i];
                }
                num[a][b][c] %= mod;
                num[a][b][c] *= Factorial[a];
                num[a][b][c] %= mod;
                num[a][b][c] *= Factorial[b];
                num[a][b][c] %= mod;
                num[a][b][c] *= Factorial[c];
                num[a][b][c] %= mod;
                //cerr << a << " " << b << " "<< c << " " << dp[a][b][c][1] << endl;
                dp[a+1][b][c][1] += (dp[a][b][c][2] + dp[a][b][c][3]);
                dp[a][b+1][c][2] += (dp[a][b][c][1] + dp[a][b][c][3]);
                dp[a][b][c+1][3] += (dp[a][b][c][1] + dp[a][b][c][2]);
            }
        }
    }
    for(int i = 1; i <= 3; i++) napsack[0][0][i] = 1;
    for(int i = 1; i <= N; i++) {
        ll t, g;
        cin >> t >> g;
        for(int beforenum = N; beforenum >= 0; beforenum--) {
            for(int beforeval = 0; beforeval <= T; beforeval++) {
                napsack[beforenum+1][beforeval+t][g] += napsack[beforenum][beforeval][g];
                napsack[beforenum+1][beforeval+t][g] %= mod;
            }
        }
    }
    vector<query> queries[4];
    for(int g = 1; g <= 3; g++) {
        for(int num = 0; num <= N; num++) {
            for(int val = 0; val <= T; val++) {
                if(napsack[num][val][g] != 0) {
                    queries[g].emplace_back(num, napsack[num][val][g], val);
                    //cerr << g << " " << num << " " << val << " "<< napsack[num][val][g] << endl;
                }
            }
        }
        sort(queries[g].begin(), queries[g].end());
    }
    for(int i = 0; i < queries[1].size(); i++) {
        for(int j = 0; j < queries[2].size(); j++) {
            if(queries[1][i].val + queries[2][j].val > T) break;
            auto itr = lower_bound(queries[3].begin(), queries[3].end(), query(0, 0, T - queries[1][i].val - queries[2][j].val));
            int k = distance(queries[3].begin(), itr);
            for(; k < queries[3].size(); k++) {
                if(queries[1][i].val + queries[2][j].val + queries[3][k].val != T) break;
                ll nowval = num[queries[1][i].num][queries[2][j].num][queries[3][k].num];
                nowval *= queries[1][i].factor;
                nowval %= mod;
                nowval *= queries[2][j].factor;
                nowval %= mod;
                nowval *= queries[3][k].factor;
                nowval %= mod;
                ans = (ans + nowval) % mod;
            }
        }
    }
    cout << ans << endl;
    return 0;
}