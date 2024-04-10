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
const int maxn = (int)2e5 + 12, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
  
template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    }
}

int n, m;
string s;

int question_mark[maxn];

bool ok[maxn];

int cnt(int l, int r) {
    return question_mark[r] - (l == 0 ? 0 : question_mark[l - 1]);
}

void precalc1() {
    int cntA = 0, cntB = 0;
    for (int i = 0; i < m; i++) {
        if (i % 2 == 0) {
            if (s[i] == 'b')
                cntB++;
        } else {
            if (s[i] == 'a')
                cntA++;
        }
    }
    for (int i = 0;; i += 2) {
        if (cntA == 0 && cntB == 0)
            ok[i] = 1;
        if (i + m + 1 >= n)
            break;
        if (s[i] == 'b')
            cntB--;
        if (s[i + 1] == 'a')
            cntA--;

        if ((i + m) % 2 == 0) {
            if (s[i + m] == 'b')
                cntB++;
        } else {
            if (s[i + m] == 'a')
                cntA++;
        }

        if ((i + m + 1) % 2 == 0) {
            if (s[i + m + 1] == 'b')
                cntB++;
        } else {
            if (s[i + m + 1] == 'a')
                cntA++;
        }
    }
}

void precalc2() {
    if (n == m)
        return;
    int cntA = 0, cntB = 0;
    for (int i = 1; i <= m; i++) {
        if (i % 2 == 1) {
            if (s[i] == 'b')
                cntB++;
        } else {
            if (s[i] == 'a')
                cntA++;
        }
    }
    for (int i = 1;; i += 2) {
        if (cntA == 0 && cntB == 0)
            ok[i] = 1;
        if (i + m + 1 >= n)
            break;
        if (s[i] == 'b')
            cntB--;
        if (s[i + 1] == 'a')
            cntA--;

        if ((i + m) % 2 == 1) {
            if (s[i + m] == 'b')
                cntB++;
        } else {
            if (s[i + m] == 'a')
                cntA++;
        }

        if ((i + m + 1) % 2 == 1) {
            if (s[i + m + 1] == 'b')
                cntB++;
        } else {
            if (s[i + m + 1] == 'a')
                cntA++;
        }
    }
}

pair<int, int> pr[maxn], sf[maxn];

int main() {
    // files1;
    fast_io;
    cin >> n >> s >> m;

    if (m > n) {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '?')
            question_mark[i]++;
        if (i)
            question_mark[i] += question_mark[i - 1];
    }

    if (m != 1) {
        precalc1();
        precalc2();
    } else {
        for (int i = 0; i < n; i++) {
            ok[i] = 1;
            if (s[i] == 'b')
                ok[i] = 0;
        }
    }

    bool cntok = 0;
    for (int i = 0; i < n; i++) {
        if (ok[i]) cntok = 1;
        // cout << ok[i] << endl;
    }

    if (!cntok) {
        cout << 0;
        return 0;
    }

    for (int i = m - 1; i < n; i++) { // [m - 1, n - 1]
        pii cur = mp(0, 0);
        if (ok[i - m + 1]) {
            cur.f += 1;
            cur.s -= cnt(i - m + 1, i);
        }
        if (i - m >= 0) {
            cur.f += pr[i - m].f;
            cur.s += pr[i - m].s;
        }

        pr[i] = cur;
        if (i > 0)
            pr[i] = max(pr[i], pr[i - 1]);
    }

    for (int i = n - m; i >= 0; i--) { // [0, n - m]
        pii cur = mp(0, 0);
        if (ok[i]) {
            cur.f += 1;
            cur.s -= cnt(i, i + m - 1);
        }
        if (i + m < n) {
            cur.f += sf[i + m].f;
            cur.s += sf[i + m].s;
        }

        sf[i] = cur;
        if (i + 1 < n)
            sf[i] = max(sf[i], sf[i + 1]);
    }

    pii res = mp(0, 0);
    for (int i = 0; i < n; i++)
        if (ok[i]) {
            pii cur = mp(1, -cnt(i, i + m - 1));
            if (i > 0) {
                cur.f += pr[i - 1].f;
                cur.s += pr[i - 1].s;
            }
            if (i + m < n) {
                cur.f += sf[i + m].f;
                cur.s += sf[i + m].s;
            }
            amax(res, cur);
        }
    // cout << res.f << endl;
    cout << -res.s << endl;
    return 0;
}