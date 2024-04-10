#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int mod = 998244353;
const int root = 805775211;
const int DEG = 19;
const int N = 1 << DEG;

ll binpow(ll x, ll p){
    ll ans = 1;
    while(p){
        if(p & 1LL){
            ans = (ans * x) % mod;
        }
        x = (x * x) % mod;
        p >>= 1;
    }
    return ans;
}

ll rev(ll x){
    return binpow(x, mod - 2);
}

vector<int> w;
vector<int> bw;

void fft(vector<int>& v){
    for(int i = 0; i < N; ++i){
        if(bw[i] > i){
            swap(v[i], v[bw[i]]);
        }
    }
    for(int step = 2, half = 1, sh = DEG - 1; sh >= 0; step <<= 1, half <<= 1, --sh){
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


int main() {
    ios_base::sync_with_stdio(false);
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    int n, m, k;

    cin >> n >> m >> k;
    string s, t;
    cin >> s >> t;
    unordered_map<char, int> mp;
    mp['A'] = 0;
    mp['T'] = 1;
    mp['G'] = 2;
    mp['C'] = 3;
    for(int i = 0; i < n; ++i){
        s[i] = mp[s[i]];
    }
    for(int i = 0; i < m; ++i){
        t[i] = mp[t[i]];
    }
    w.resize(N + 1);
    bw.resize(N);
    w[0] = 1;
    for(int i = 1; i <= N; ++i){
        w[i] = (w[i - 1] * ll(root)) % mod;
    }
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
    vector<vector<int>> can(4, vector<int>(N, 0));
    vector<int> last(4, -k - 9);
    for(int i = 0; i < n; ++i){
        last[s[i]] = i;
        for(int j = 0; j < 4; ++j){
            if(last[j] >= i - k){
                can[j][i] = 1;
               // cout << j << " " << i << endl;
            }
        }
    }
    last.clear();
    last.resize(4, n + 9 + k);
    for(int i = n - 1; i >= 0; --i){
        last[s[i]] = i;
        for(int j = 0; j < 4; ++j){
            if(last[j] <= i + k){
                can[j][i] = 1;
              //  cout << j << " " << i << endl;
            }
        }
    }
    const int E2E5 = 200000;
    vector<vector<int>> is(4, vector<int>(N, 0));
   // cout << "~~" << endl;
    for(int i = 0; i < m; ++i){
        is[t[i]][E2E5 - i] = 1;
       // cout << (int)t[i] << " " << -i << endl;
    }
    for(int i = 0; i < 4; ++i){
        fft(can[i]);
        fft(is[i]);
    }
    vector<int> ans(N, 0);
    for(int j = 0; j < N; ++j){
        for(int i = 0; i < 4; ++i){
            ans[j] += (can[i][j] * ll(is[i][j])) % mod;
            ans[j] %= mod;
        }
    }
    reverse(ans.begin() + 1, ans.end());
    fft(ans);
    ll revn = rev(N);
    for(int i = 0; i < N; ++i){
        ans[i] = (ans[i] * revn) % mod;
    }
    int res = 0;
    for(int i = 0; i < n - m + 1; ++i){
        //cout << ans[E2E5 + i] << " ";
        if(ans[E2E5 + i] == m){
            ++res;
            //cerr << i << " ";
        }
    }
    cout << res << endl;


}