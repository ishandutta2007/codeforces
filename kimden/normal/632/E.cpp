#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, k;
vector<int> a;
int mn;
vector<int> ans;

ll binpow(ll x, ll p, ll mod){
    ll ans = 1;
    while(p){
        if(p & 1LL){
            ans = (ans * x) % mod;
        }
        p >>= 1LL;
        x = (x * x) % mod;
    }
    return ans;
}

void fft(vector<int>& v, int mod, int deg, int N, vector<int>& w, vector<int>& bw){
    for(int i = 0; i < N; ++i){
        if(bw[i] > i){
            swap(v[i], v[bw[i]]);
        }
    }
    for(int step = 2, half = 1, sh = deg - 1; sh >= 0; step <<= 1, half <<= 1, --sh){
        for(int i = 0; i < N; i += step){
            for(int j = 0; j < half; ++j){
                int a = v[i + j];
                int b = (v[i + j + half] * ll(w[j << sh])) % mod;
                v[i + j] = (a + b) % mod;
                v[i + j + half] = (a + mod - b) % mod;
            }
        }
    }
}

void solve(int mod, int maxdeg, int root0, int deg){
    int root = root0;
    for(int i = 0; i < maxdeg - deg; ++i){
        root = (root * ll(root)) % mod;
    }
    int N = 1 << deg;
    vector<int> x(N, 0);
    for(int i = 0; i < n; ++i){
        x[a[i] - mn] = 1;
    }
    vector<int> w(N), bw(N);
    int cur = 0;
    bw[0] = cur;
    for(int i = 1; i < N; ++i){
        for(int j = (N >> 1); j > 0; j >>= 1){
            cur ^= j;
            if(cur & j){
                break;
            }
        }
        bw[i] = cur;
    }
    w[0] = 1;
    for(int i = 1; i < N; ++i){
        w[i] = (w[i - 1] * ll(root)) % mod;
    }
    fft(x, mod, deg, N, w, bw);
    for(int i = 0; i < N; ++i){
        x[i] = binpow(x[i], k, mod);
    }
    ll revn = binpow(N, mod - 2, mod);
    reverse(x.begin() + 1, x.end());
    fft(x, mod, deg, N, w, bw);
    for(int i = 0; i < N; ++i){
    //    x[i] = (x[i] * revn) % mod;
        if(x[i]){
            ans[i] = 1;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    cin >> n >> k;
    a.resize(n);
    mn = 999999999;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    ans.resize(1 << 20, 0);
    solve(167772161, 21, 39, 20);
    solve(469762049, 23, 82, 20);
    for(int i = 0; i < ans.size(); ++i){
        if(ans[i]){
            cout << i + mn * k << " ";
        }
    }
    cout << endl;


}