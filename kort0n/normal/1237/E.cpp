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
ll N;
ll num, Beki, depth;
ll dpnum[2005000];
ll dpfree[2000500];
bool NG = false;
void f(ll now, ll pos, ll dep) {
    //cerr << "calling: " << now << " " << pos << " " << dep << endl;
    if(dep == depth) {
        if(pos == 0) {
            dpfree[now] = 1;
        }
        return;
    }
    int left = now*2 + 1;
    int right = now*2 + 2;
    f(left, 0, dep+1);
    f(right, 1, dep+1);
    if(pos == 0) {
        if(dpnum[right] % 2 == 1) {
            dpfree[right]--;
            dpnum[right]++;
        } else {
            dpfree[now] = 0;
        }
        if(dpfree[right] < 0) NG = true;
    }
    if(pos == 1) {
        if(dpnum[left] % 2 == 0) {
            dpfree[left]--;
            dpnum[left]++;
        } else {
            dpfree[left] = 0;
        }
        if(dpfree[left] < 0) NG = true;
    }
    dpnum[now] += dpnum[left];
    dpfree[now] += dpfree[left];
    dpnum[now] += dpnum[right];
    dpfree[now] += dpfree[right];
    dpnum[now]++;
    if(dpfree[now] < 0) {
        NG = true;
    }
    //cerr << "f:" << now << " " << dpnum[now] << " " << dpfree[now] << endl;
}
ll inv[10000100];
ll FactorialInv[10000100];
ll Factorial[10000100];
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
    if(a < 0) return 0;
    if(b < 0) return 0;
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    init_combination();
    cin >> N;
    if(N == 1 || N == 2) {
        cout << 1 << endl;
        return 0;
    }
    Beki = 1;
    num = 1;
    depth = 0;
    while(true) {
        Beki *= 2;
        num += Beki;
        depth++;
        if(num >= N) break;
    }
    cerr << num << " " << depth << endl;
    f(0, -1, 0);
    if(NG) {
        cout << 0 << endl;
        return 0;
    }
    ll Rest = N - dpnum[0];
    cout << combination(dpfree[0], Rest) << endl;
    //if(dpnum[0] <= N && N <= dpnum[0] + dpfree[0]) cout << 1 << endl;
    return 0;
}