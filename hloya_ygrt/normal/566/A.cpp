// hloya template v24

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
#define files2 freopen("data.out","w",stdout)
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
const int maxn = 1e5 + 12, base = (int)1e9 + 7;
const ll llinf = 4e18 + 5;

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

const int maxE = 8e5 + 100;

int tree[maxE][26], depth[maxE];
vector<int> of_type[maxE][2];
int sz = 1;

string s[maxn], t[maxn];

void add(string& s, int type, int it) {
    int v = 1;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (tree[v][c] == 0) {
            tree[v][c] = ++sz;
        }
        v = tree[v][c];
    }
    of_type[v][type].pb(it);
}

vector<int> a, b;

vector<int> rest[maxE][2];
vector<int> curA, curB;

void dfs(int v) {
    // cout << v << endl;
    curA = of_type[v][0];
    curB = of_type[v][1];

    while (!curA.empty() && !curB.empty()) {
        a.pb(curA.back());
        b.pb(curB.back());
        curA.pop_back();
        curB.pop_back();
    }

    while (!curA.empty()) {
        rest[v][0].pb(curA.back());
        curA.pop_back();
    }
    while (!curB.empty()) {
        rest[v][1].pb(curB.back());
        curB.pop_back();
    }
    for (int i = 0; i < 26; i++) {
        if (tree[v][i]) {
            int to = tree[v][i];
            dfs(to);
            curA.clear();
            curB.clear();

            for (int j : rest[to][0]) {
                if (!rest[v][1].empty()) {
                    a.pb(j);
                    b.pb(rest[v][1].back());
                    rest[v][1].pop_back();
                    continue;             
                }                         
                curA.pb(j);
            }
            for (int j : rest[to][1]) {
                if (!rest[v][0].empty()) {
                    a.pb(rest[v][0].back());
                    b.pb(j);
                    rest[v][0].pop_back();
                    continue;
                }
                curB.pb(j);
            }
            while (!curA.empty()) {
                rest[v][0].pb(curA.back());
                curA.pop_back();
            }
            while (!curB.empty()) {
                rest[v][1].pb(curB.back());
                curB.pop_back();
            }
        }
    }
}

int main() {
    int n;
    fast_io;
    // files1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> s[i];
        add(s[i], 0, i);
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        add(t[i], 1, i);
    }
    dfs(1);
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        int res = 0;
        for (int j = 0; j < min(s[a[i]].size(), t[b[i]].size()); j++) {
            if (s[a[i]][j] != t[b[i]][j])
                break;
            res++;
        }
        // cout << s[a[i]] << ' ' << t[b[i]] << endl;
        ans += res;
    }
    // return 0;
    cout << ans << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] + 1 << ' ' << b[i] + 1 << endl;
    }
    return 0;
}