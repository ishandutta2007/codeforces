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
using namespace std;
  
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
#define ll long long int
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

ll gcd (ll a, ll b) { while (b) { a %= b; swap (a, b); } return a; }
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)4e5 + 12, base = 1e9 + 7;
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

map<int, int> sot;
int cnt;

set<int> s[maxn];
int wh[maxn];
vector<pair<int, int> > g[maxn];

int to_up[maxn];

void init(int pos) { // [-1, 2^30)
    wh[pos] = pos;
    s[pos].insert(pos);
    to_up[pos] = 0;
}

void dfs(int v, int p, int x) {
    to_up[v] = x;
    for (auto e : g[v]) {
        int to = e.f, len = e.s;
        if (to == p) continue;
        dfs(to, v, x ^ len);
    }
}

void try_merge(int a, int b, int x) {
    a = sot[a];
    b = sot[b];
    if (wh[a] == wh[b])
        return;

    int s1 = wh[a], s2 = wh[b];
    if (s[s1].size() > s[s2].size()) {
        swap(a, b);
        swap(s1, s2);
    }

    dfs(a, -1, to_up[b] ^ x);
    g[a].pb(mp(b, x));
    g[b].pb(mp(a, x));

    for (int e : s[s1]) {
        wh[e] = s2;
        s[s2].insert(e);
    }
    s[s1].clear();
}

int get_ans(int a, int b){ 
    a = sot[a];
    b = sot[b];
    if (wh[a] == wh[b]) {
        return to_up[a] ^ to_up[b];
    } else return -1;
}


int main() {
    int q;
    fast_io;
    // files1;
    cin >> q;

    int last = 0;

    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l^=last;
            r^=last;
            x^=last;
            if (l > r) swap(l, r);

            l--;

            if (!sot.count(l)) {
                sot[l] = cnt;
                init(cnt);
                cnt++;
            }
            if (!sot.count(r)) {
                sot[r] = cnt;
                init(cnt);
                cnt++;
            }

            try_merge(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;

            l^=last;
            r^=last;

            if (l > r) swap(l, r);
            l--;

            if (!sot.count(l)) {
                sot[l] = cnt;
                init(cnt);
                cnt++;
            }
            if (!sot.count(r)) {
                sot[r] = cnt;
                init(cnt);
                cnt++;
            }
            
            last = get_ans(l, r);

            cout << last << "\n";
            if (last == -1)
                last = 1;
        }
    }
    return 0;
}