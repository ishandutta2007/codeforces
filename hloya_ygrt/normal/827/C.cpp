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
#define files2 freopen("out2.txt","w",stdout)
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

inline int popcount(int x){
    int count = 0;
    __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
    return count;
}
  
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
  
const int inf = 2e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = 1e5 + 12, base = 1e9 + 7;
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

int tree[400][maxn];

void add(const int& a, const int& b, const int& c, int pos, const int& val) {
    int it = a * 100 + b * 10 + c;
    pos++;
    while (pos < maxn) {
        tree[it][pos] += val;
        pos += pos & -pos;
    }
}

int sum(const int& a, const int& b, const int& c, int r) {
    int it = a * 100 + b * 10 + c;
    r++;
    int ans = 0;
    while (r > 0) {
        ans += tree[it][r];
        r -= r & -r;
    }
    return ans;
}

string s, e;

int get(char ch) {
    if (ch == 'A')
        return 0;
    if (ch == 'T')
        return 1;
    if (ch == 'G')
        return 2;
    if (ch == 'C')
        return 3;
    while (1);
    return 4;
}

void addLetter(char ch, int pos) {
    int a = get(ch);
    for (int c = 1; c <= 10; c++) {
        int b = pos % c;
        add(a, b, c - 1, pos, 1);
    }
}

void delLetter(char ch, int pos) {
    int a = get(ch);
    for (int c = 1; c <= 10; c++) {
        int b = pos % c;
        add(a, b, c - 1, pos, -1);
    }
}

int main() {
    // files1;
    fast_io;
    cin >> s;

    for (int i = 0; i < s.size(); i++)
        addLetter(s[i], i);

    int q;
    cin >> q;

    for (int j = 0; j < q; j++) {
        int t;
        cin >> t;
        if (t == 1) {
            int pos;
            char ch;
            cin >> pos >> ch;

            pos--;
            delLetter(s[pos], pos);
            s[pos] = ch;
            addLetter(s[pos], pos);
        } else {
            int l, r;
            cin >> l >> r;
            cin >> e;

            int c = e.size();
            l--; r--;

            int ans = 0;
            for (int i = 0; i < e.size(); i++) {
                int b = (i + l) % c;
                ans += sum(get(e[i]), b, c - 1, r);
                if (l)
                ans -= sum(get(e[i]), b, c - 1, l - 1);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}