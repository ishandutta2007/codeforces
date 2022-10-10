#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 998244353;

template <class T>
T fexp(T x, long long e) {
    T ans(1);
    for(; e > 0; e /= 2) {
        if(e & 1) ans = ans * x;
        x = x * x;
    }
    return ans;
}

template <int mod = MOD>
struct modBase {
    modBase(int v = 0) : val(v < 0 ? v + mod : v) {}
    int val;
 
    void operator += (modBase<mod> o) { *this = *this + o; }
    void operator -= (modBase<mod> o) { *this = *this - o; }
    void operator *= (modBase<mod> o) { *this = *this * o; }
    //void operator /= (modBase<mod> o) { *this = *this / o; }
    modBase<mod> operator * (modBase<mod> o) { return (int)((long long) val * o.val % mod); }
    //modBase<mod> operator / (modBase<mod> o) { return *this * fexp(o, mod - 2); }
    modBase<mod> operator + (modBase<mod> o) { return val + o.val >= mod ? val + o.val - mod : val + o.val; }
    modBase<mod> operator - (modBase<mod> o) { return val - o.val < 0 ? val - o.val + mod : val - o.val; }

    friend std::ostream& operator << (std::ostream &os, const modBase<mod> &p) {
        return os << p.val;
    }
    friend std::istream& operator >> (std::istream &is, modBase<mod> &p) {
        return is >> p.val;
    }
};

const int ms = 5050;

modBase<> fat[ms], ifat[ms];
void initComb() {
    fat[0] = 1;
    for(int i = 1; i < ms; i++) {
        fat[i] = fat[i-1] * i;
    }
    ifat[ms-1] = fexp(fat[ms-1], MOD - 2);
    for(int i = ms-1; i > 0; i--) {
        ifat[i-1] = ifat[i] * i;
    }
}
modBase<> comb(int n, int a) { return a < 0 || a > n ? modBase<>(0) : fat[n] * ifat[a] * ifat[n-a]; }
int f[ms], sum[ms];
modBase<> dp[ms/2][ms];

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    initComb();
    int t;
    std::cin >> t;
    while(t--) {
        int n;
        std::cin >> n;
        for(int i = 0; i < n; i++) {
            f[i] = sum[i] = 0;
        }
        for(int i = 0; i < n; i++) {
            int x;
            std::cin >> x;
            f[x-1]++;
        }
        for(int i = 1; i < n; i++) sum[i] = sum[i-1] + f[i-1];
        for(int i = 0; i <= n/2; i++) for(int j = 0; j <= n; j++) dp[i][j] = 0;
        dp[0][0] = 1;
        for(int i = 0; i < n/2; i++) for(int j = 0; j < n; j++) {
            if(dp[i][j].val == 0) continue;
            int prev = i == 0 ? 0 : 2 * i + 1, extra = i == 0 ? 1 : 0;
            dp[i][j+1] += dp[i][j];
            //std::cout << "(" << i << ", " << j << ") = " << dp[i][j] << '\n';
            for(int k = 1; i+k <= n/2 && k+extra-(i+k==n/2?1:0) <= sum[j]-prev && k <= f[j] && k <= 1; k++) {
                //std::cout << "making transition with " << k << ": " << comb(f[j], k) << ", " << fat[k] << ", " << fat[sum[j]-prev] * ifat[sum[j]-prev-k-extra+(i+k==n/2?1:0)] << '\n';
                dp[i+k][j+1] += dp[i][j] * comb(f[j], k) * fat[k] * fat[sum[j]-prev] * ifat[sum[j]-prev-k-extra+(i+k==n/2?1:0)];
            }
        }
        modBase<> ans(0);
        for(int i = 0; i <= n; i++) ans += dp[n/2][i];
        for(int i = 0; i < n; i++) {
            ans *= ifat[f[i]];
        }
        std::cout << ans << '\n';
    }
}