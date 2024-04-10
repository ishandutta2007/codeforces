#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int mod = 998244353;
const int deg = 18;
const int root = 841431251;
const int maxn = 1 << deg;
const int letters = 6;
int w[maxn];
int bw[maxn];
int a[letters][maxn];
int b[letters][maxn];
int z[letters][letters][maxn];
int dsu[maxn][6];
int cnt[maxn];

int get(int d[], int idx){
    if(d[idx] <= 0) {
        return idx;
    }
    int res = get(d, d[idx] - 1);
    d[idx] = res + 1;
    return res;
}
int unite(int d[], int u, int v){
    u = get(d, u);
    v = get(d, v);
    if(u == v){
        return 0;
    }
    if(d[u] > d[v]){
        swap(u, v);
    }
    d[u] -= (-d[v] + 1);
    d[v] = u + 1;
    return 1;
}

int binpow(int x, int p){
    int ans = 1;
    while(p){
        if(p & 1){
            ans = (ans * ll(x)) % mod;
        }
        x = (x * ll(x)) % mod;
        p >>= 1;
    }
    return ans;
}

int rev(int x){
    return binpow(x, mod - 2);
}

const ll revmaxn = rev(maxn);

void fft(int v[]){
    for(int i = 0; i < maxn; ++i){
        if(i < bw[i]){
            swap(v[i], v[bw[i]]);
        }
    }
    for(int step = 2, half = 1, shift = deg - 1; step <= maxn; step <<= 1, half <<= 1, --shift){
        for(int i = 0; i < maxn; i += step){
            for(int j = 0; j < half; ++j){
                int a = v[i + j];
                int b = (v[i + j + half] * ll(w[j << shift])) % mod;
                v[i + j] = (a + b) % mod;
                v[i + j + half] = (a + mod - b) % mod;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int cur = 0;
    for(int i = 0; i < maxn; ++i){
        bw[i] = cur;
        for(int j = (1 << (deg - 1)); j; j >>= 1){
            cur ^= j;
            if(cur & j){
                break;
            }
        }
    }
    w[0] = 1;
    for(int i = 1; i < maxn; ++i){
        w[i] = (w[i - 1] * ll(root)) % mod;
    }
    string s, t;
    cin >> s >> t;
    reverse(all(t));
    for(int i = 0; i < s.length(); ++i){
        a[s[i] - 'a'][i] = 1;
    }
    for(int i = 0; i < t.length(); ++i){
        b[t[i] - 'a'][i] = 1;
    }
    for(int i = 0; i < letters; ++i){
        fft(a[i]);
        fft(b[i]);
    }
    for (int i = 0; i < letters; ++i) {
        for (int j = i + 1; j < letters; ++j) {
            for (int u = 0; u < maxn; ++u) {
                z[i][j][u] = ((a[i][u] * ll(b[j][u])) % mod + (a[j][u] * ll(b[i][u])) % mod) % mod;
            }
            reverse(z[i][j] + 1, z[i][j] + maxn);
            fft(z[i][j]);
            for(int u = t.length() - 1; u < s.length(); ++u){
                //z[i][j][u] = (z[i][j][u] * ll(revmaxn)) % mod; // not needed as we check if != 0 only
                if(z[i][j][u]){
                    cnt[u] += unite(dsu[u], i, j);
                }
            }
        }
    }
    for(int i = t.length() - 1; i <= s.length() - 1; ++i){
        cout << cnt[i] << " ";
    }
    cout << endl;
    return 0;
}