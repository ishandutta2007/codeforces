// hloya template v25
  
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
#include <valarray>
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>
  
#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
  
#define endl '\n'
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
  
template<typename T>
void amax(T& x, T y) {
    x = max(x, y);
}
  
template<typename T>
void amin(T& x, T y) {
    x = min(x, y);
}

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
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)1e6 + 12, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
  
template<typename T>
T binpow(T n, T s, T mod)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2, mod);
        return ( 1LL * b * b ) % mod;
    } else {
        return (1LL* binpow(n, s - 1, mod) * n) % mod;
    }
}

const vector<int> p = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087, 1000000093, 1000000097, 1000000103,
                 1000000123, 1000000181, 1000000207, 1000000223, 1000000241, 1000000271};

vector<int> sum[20];    
vector<int> pw10[20];
vector<int> inv10[20];
int n, m;

string s;

bool leadZero(int l, int r) {
    if (r - l + 1 > 1 && s[l] == '0')
        return 1;
    return 0;
}

int getsum(const int& i, const int& l, const int& r) {
    int s = sum[i][l] - (r == n - 1 ? 0 : sum[i][r + 1]);
    if (s < 0)
        s += p[i];
    return 1ll * inv10[i][n - r - 1] * s % p[i];
}

inline void try__(const int& l1, const int& r1, const int& l2, const int& r2, const int& l3, const int& r3) {
    for (int i = 0; i < m; i++) {
        int a = getsum(i, l1, r1), b = getsum(i, l2, r2), c = getsum(i, l3, r3);
        a += b;
        if (a >= p[i])
            a -= p[i];
        if (a != c)
            return;
    }

    cout << s.substr(l1, r1 - l1 + 1) << '+' << s.substr(l2, r2 - l2 + 1) << '=' << s.substr(l3);
    exit(0);
}

void gen() {
    ofstream cout("input.txt");
    for (int i = 0; i < (int)1e6; i++)
        cout << char(rand() % 9 + '1');
}

int main() {
    // gen();
    // return 0;
    fast_io;
    // files1;

    cin >> s;

    n = s.size();
    m = p.size();

    for (int i = 0; i < m; i++) {
        sum[i].resize(n);
        pw10[i].resize(n);
        inv10[i].resize(n);

        pw10[i][0] = inv10[i][0] = 1;
        int curInv = binpow(10, p[i] - 2, p[i]);

        for (int j = 1; j < n; j++) {
            pw10[i][j] = 1ll * pw10[i][j - 1] * 10 % p[i];
            inv10[i][j] = 1ll * inv10[i][j - 1] * curInv % p[i];
        }

        for (int j = n - 1; j >= 0; j--) {
            sum[i][j] = 1ll * (s[j] - '0') * pw10[i][n - j - 1] % p[i];
            if (j != n - 1) {
                sum[i][j] += sum[i][j + 1];
                if (sum[i][j] >= p[i])
                    sum[i][j] -= p[i];
            }
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        // [i .. n - 1];
        int l = n - i;

        // 1
        // [0 .. i - len - 1] + [i - len, i - 1]
        if (i - l - 1 >= 0 && i - l <= l && !leadZero(0, i - l - 1) && !leadZero(i - l, i - 1)) {
            try__(0, i - l - 1, i - l, i - 1, i, n - 1);
        }

        // 2
        // [0 .. i - l] + [i - l + 1, i - 1]
        if (l != 1 && i - l >= 0 && i - l + 1 <= l - 1 && !leadZero(0, i - l) && !leadZero(i - l + 1, i - 1)) {
            try__(0, i - l, i - l + 1, i - 1, i, n - 1);
        }

        // 3
        // [0 .. l - 1] + [l, i - 1]
        if (l <= i - 1 && i - l <= l && !leadZero(0, l - 1) && !leadZero(l, i - 1)) {
            try__(0, l - 1, l, i - 1, i, n - 1);
        }

        // 4
        // [0, l - 2] + [l - 1, i - 1]
        if (l != 1 && i - l >= 0 && i - l + 1 <= l - 1 && !leadZero(0, l - 2) && !leadZero(l - 1, i - 1)) {
            try__(0, l - 2, l - 1, i - 1, i, n - 1);
        }
    }

    // cout << current_time << endl;
    exit(228);
    return 0;
}