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
const int maxn = (int)2e5 + 12;//, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
 
const int mod= 1e9 + 7;
  
template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % mod;
    } else {
        return (1LL* binpow(n, s - 1) * n) % mod;
    }
}

struct bor {
    struct vertex {
        const static int K = 26;
        int next[K];
        int sum;
        int p;
        char pch;
        int link;
        int go[K];
    };
     
    vertex t[maxn+1];
    int sz;

    bool used[maxn + 1];
     
    void init() {
        t[0].p = t[0].link = -1;
        memset (t[0].next, 255, sizeof t[0].next);
        memset (t[0].go, 255, sizeof t[0].go);
        sz = 1;
        memset(used, 0, sizeof(used));
    }
     
    void add_string (const string & s) {
        int v = 0;
        for (size_t i=0; i<s.length(); ++i) {
            char c = s[i]-'a';
            if (t[v].next[c] == -1) {
                memset (t[sz].next, 255, sizeof t[sz].next);
                memset (t[sz].go, 255, sizeof t[sz].go);
                t[sz].link = -1;
                t[sz].p = v;
                t[sz].pch = c;
                t[v].next[c] = sz++;
            }
            v = t[v].next[c];
        }
        t[v].sum++;
    }
     
    // int go (int v, char c);
     
    int get_link (int v) {
        if (t[v].link == -1)
            if (v == 0 || t[v].p == 0)
                t[v].link = 0;
            else
                t[v].link = go (get_link (t[v].p), t[v].pch);
        return t[v].link;
    }
     
    int go (int v, char c) {
        if (t[v].go[c] == -1)
            if (t[v].next[c] != -1)
                t[v].go[c] = t[v].next[c];
            else
                t[v].go[c] = v==0 ? 0 : go (get_link (v), c);
        return t[v].go[c];
    }

    void mda(int v) {
        used[v] = 1;
        int nxt = get_link(v);
        if (!used[nxt]) {
            mda(nxt);
        }
        t[v].sum += t[nxt].sum;
    }

    void process() {
        for (int i = 1; i < sz; i++) {
            if (!used[i]) {
                mda(i);
            }
        }
    }
};
 
int main() {
    // files1;

    string t;
    cin >> t;

    bor a, b;
    int n;
    cin >> n;

    a.init();
    b.init();

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.add_string(s);
        reverse(all(s));
        b.add_string(s);
    }
    // return 0;
    a.process();

    b.process();

    vector<int> dp1(t.size(), 0), dp2(t.size(), 0);

    for (int i = 0, v = 0; i < t.size(); i++) {
        v = a.go(v, t[i] - 'a');
        dp1[i] = a.t[v].sum;
    }
    for (int i = t.size() - 1, v = 0; i >= 0; i--) {
        v = b.go(v, t[i] - 'a');
        dp2[i] = b.t[v].sum;
    }

    ll res = 0;
    for (int i = 0; i + 1 < t.size(); i++) {
        res += 1ll * dp1[i] * dp2[i + 1];
    }
    cout << res;

    return 0;
}