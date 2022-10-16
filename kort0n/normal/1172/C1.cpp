#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef pair<l_l, ll> lll;
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

void print(ll a) {
    for(ll b = 1; b <= 1e4; b++) {
        if((a * b % mod) <= 1e4) {
            cerr << (a*b) % mod << "/" << b << endl;
            return;
        }
    }
    cerr << "NO" << endl;
}

ll N, M;
ll a[200500];
ll w[200050];
ll sum[2];
ll Prev[200][200];
ll Next[200][200];
//l_l nowdp[200050];
//l_l othersdp[200050];
l_l othersval[205];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    init_combination();
    cin >> N >> M;
    for(int i = 1; i <= N; i++) cin >> a[i];
    for(int i = 1; i <= N; i++) cin >> w[i];
    for(int i = 1; i <= N; i++) {
        sum[a[i]] += w[i];
    }
    for(int i = 1; i <= N; i++) {
    //for(int i = 2; i <= 2; i++) {
        /*
        othersval[0] = {sum[0], sum[1]};
        if(a[i] == 0) othersval[0].first -= w[i];
        else othersval[0].second -= w[i];
        cerr << "0 " << othersval[0].first << " " << othersval[0].second << endl;
        for(int j = 1; j <= M; j++) {
            ll delta[2];
            ll sum = (othersval[j-1].first + othersval[j-1].second) % mod;
            delta[0] = othersval[j-1].first * beki(sum, mod - 2) % mod;
            delta[1] = othersval[j-1].second * beki(sum, mod - 2) % mod;
            othersval[j].first = (othersval[j-1].first - delta[0] + mod) % mod;
            othersval[j].second = (othersval[j-1].second + delta[1] + mod) % mod;
            cerr << j << " " << othersval[j].first << " " << othersval[j].second << endl;
            print(othersval[j].first);
            print(othersval[j].second);
        }
        */
        for(int i = 0; i <= M; i++) {
            for(int j = 0; j <= M; j++) {
                Prev[i][j] = 0;
                Next[i][j] = 0;
            }
        }
        Prev[0][0] = 1;
        for(int time = 1; time <= M; time++) {
            for(int j = 0; j <= M; j++) {
                for(int k = 0; k <=M; k++) Next[j][k] = 0;
            }
            for(int j = 0; j < time; j++) {
                for(int k = 0; j + k < time; k++) {
                    ll valnow, valzero, valone;
                    if(a[i]) {
                        valnow = w[i] + j;
                        valzero = sum[0] - k;
                        valone = sum[1] - w[i] + (time - 1 - k - j);
                    } else {
                        valnow = w[i] - j;
                        valzero = sum[0] - w[i] - k;
                        valone = sum[1] + (time - 1 - k - j);
                    }
                    ll nowsum = (valnow + valzero + valone) % mod;
                    //cerr << time << " "<< j << " " << nowsum << endl;
                    Next[j+1][k] += Prev[j][k] * (valnow * beki(nowsum, mod - 2) % mod);
                    Next[j][k] += Prev[j][k] * (valone * beki(nowsum, mod - 2) % mod);
                    Next[j][k+1] += Prev[j][k] * (valzero * beki(nowsum, mod - 2) % mod);
                    Next[j+1][k] %= mod;
                    Next[j][k] %= mod;
                    Next[j][k+1] %= mod;
                }
            }
            /*
            for(int j = 0; j <= time; j++) {
                cerr << time << " " << j << " " << Next[j] << endl;
                print(Next[j]);
            }*/
            swap(Prev, Next);
        }
        ll ans = 0;
        for(int j = 0; j <= M; j++) {
            ll nowval;
            if(a[i]) nowval = w[i] + j;
            else nowval = (w[i] - j) % mod;
            //cerr << i << " " << j << " " << nowval << " " << Prev[j] << endl;
            //print(Prev[j]);
            for(int k = 0; k <= M; k++) {
                ans += Prev[j][k] * nowval;
                ans %= mod;
            }
        }
        cout << ans << endl;
    }
    return 0;
}