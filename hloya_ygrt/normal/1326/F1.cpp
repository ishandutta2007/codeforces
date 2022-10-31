// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

// hloya template v26

// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 

#include <bits/stdc++.h>
using namespace std;

bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))


#define ull unsigned long long
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
  
// #define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
  
void bad(string mes = "Impossible"){cout << mes;exit(0);}
void bad(int mes){cout << mes;exit(0);}
  
template<typename T>
string bin(T x, int st = 2){
    string ans = "";
    while (x > 0){
        ans += char('0' + x % st);
        x /= st;
    }
    reverse(ans.begin(), ans.end());
    return ans.empty() ? "0" : ans;
}
  
mt19937_64 mt_rand(
    chrono::system_clock::now().time_since_epoch().count()
);

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }
  
template<typename T>
T input(){
    T ans = 0, m = 1;
    char c = ' ';
  
    while (!((c >= '0' && c <= '9') || c == '-')) {
        c = getchar();
    }
  
    if (c == '-')
        m = -1, c = getchar();
    while (c >= '0' && c <= '9'){
        ans = ans * 10 + (c - '0'), c = getchar();
    }
    return ans * m;
}

template<typename T>
T gcd (T a, T b) { while (b) { a %= b; swap (a, b); } return a; }
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)2e5 + 450, base = 998244353;
const ll llinf = 2e18 + 5;
const int mod = 1e9 + 7;

char g[14][14];

int msk;
bool us[14];

int n;
int ans = 0;

void go(int ps, int v) {
    if (ps == n - 1) {
        ans++;
        return;
    }
    bool bt = msk & (1 << ps);
    for (int j = 0; j < n; j++) {
        if (!us[j] && g[v][j] == bt) {
            us[j] = 1;
            go(ps + 1, j);
            us[j] = 0;
        }
    }
}

int posa[14], posb[14];
int cnt1[65][7], cnt2[65][7];
ll subs[129][65];

int o[7];
int z[7];

int main() {
    // files1;
    fast_io;

    cin >> n;
    // n = 14;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            g[i][j] -= '0';
            // g[i][j] = rand() % 2;
        }

    if (n < 4) {
        for (msk = 0; msk < (1 << (n - 1)); msk++) {
            ans = 0;
            for (int i = 0; i < n; i++) {
                us[i] = 1;
                go(0, i);
                us[i] = 0;
            }
            cout  << ans << ' ';
        }
        return 0;
    }

    vector<int> part(n, 1);
    int le = n / 2;
    int ri = n - le;

    for (int i = 0; i < le; i++) {
        part[i] = 0;
    }

    auto prec = [&](vector<int> pos, int tp) {
        do {
            int msk = 0;
            for (int i = 0; i + 1 < pos.size(); i++) {
                if (g[pos[i]][pos[i+1]])
                    msk |= 1 << i;
            }
            if (tp == 1) {
                cnt1[msk][posa[pos.back()]]++;
            } else {
                cnt2[msk][posb[pos.front()]]++;
            }
        } while (next_permutation(all(pos)));
    };

    vector<ll> ans(1 << (n - 1));

    // vector<vector<int>> cnt1(, vector<int>(le, 0)), cnt2(, vector<int>(ri, 0));

    vector<int> a, b;
    
    a.reserve(7);
    b.reserve(7);

    do {
        a.clear();
        b.clear();

        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));

        for (int i = 0; i < n; i++) {
            if (part[i] == 0) {
                a.push_back(i);
                posa[i] = a.size() - 1;
                posb[i] = -1;
            } else {
                b.push_back(i);
                posa[i] = -1;
                posb[i] = b.size() - 1;
            }
        }
        
        prec(a, 1);
        prec(b, 2);

        for (int i = 0; i < le; i++) {
            o[i] = 0;
            z[i] = 0;
            for (int j = 0; j < ri; j++) {
                if (g[a[i]][b[j]]) {
                    o[i] |= 1 << j;
                } else {
                    z[i] |= 1 << j;
                }
            }
        }


        for (int k = 0; k < (1 << (ri - 1)); k++) {
            subs[0][k] = 0;
            for (int i = 1; i < (1 << ri); i++) {
                int j = 31 - __builtin_clz(i);
                subs[i][k] = subs[i ^ (1 << j)][k] + cnt2[k][j];
            }
        }

        // for (int k = 0; k < (1 << (ri - 1)); k++) {
        //     // for (int j = 0; j < ri; j++) {
        //     for (int j = 0; j < (1 << ri); j++) {
        //         cout << subs[j][k] << ' ';
        //     }
        //     // }
        //     cout << endl;
        // }


        for (int i = 0; i < (1 << (le - 1)); i++)
            for (int j = 0; j < le; j++)
                if (cnt1[i][j]) {
                    for (int k = 0; k < (1 << (ri - 1)); k++) {
                        ans[i | (k << le)] += 1ll * cnt1[i][j] * subs[z[j]][k];
                        ans[i | (k << le) | (1 << (le - 1))] += 1ll * cnt1[i][j] * subs[o[j]][k];
                    }
                }
    } while (next_permutation(all(part)));

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    // cout << current_time << endl;
    return 0;
}