// hloya template v22

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

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

void bad(string mes = "Impossible"){cout << mes;exit(0);}
void bad(int mes = -1){cout << mes;exit(0);}

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

const int inf = 2e9;
const long double eps = 1e-12;
const int maxn = 3e5 + 12, base = 1e9 + 7;
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

vector<int> g[maxn];

int main() {
    int n;read(n);

    vector<pii> e;
    for (int i = 0; i < 2 * n; i++) {
        int u, v;read(u, v);
        g[u].pb(v);
        g[v].pb(u);
        e.pb(mp(min(u, v), max(u, v)));
    }
    sort(all(e));
    // return 0;
    for (int i =1 ; i <= n; i++)
        sort(all(g[i]));
    vector<int> res;
    res.pb(1);
    vector<char> used(n + 1, 0);
    used[1] = 1;

    // vector<int> st;
    // set_intersection(all(g[4]), all(g[5]), back_inserter(st));
    // cout << st.size() << endl;
    // st.clear();
    // set_intersection(all(g[4]), all(g[3]), back_inserter(st));
    // cout << st.size() << endl;
    
    // return 0;
    if (n <= 8) {
        vector<int> p;
        for (int i = 1; i <= n; i++)
            p.pb(i);
        do {
            vector<pii> ne;
            for (int i = 0; i < n; i++) {
                int t1 = p[(i + 1) % n], t2 = p[(i + 2) % n];
                ne.pb(mp(min(p[i], t1), max(p[i], t1)));
                ne.pb(mp(min(p[i], t2), max(p[i], t2)));
            }
            sort(all(ne));
            if (e == ne) {
                for (int i:p)
                    cout << i << ' ';
                return 0;
            }
        } while (next_permutation(all(p)));
        cout << -1;
        return 0;
    } 
    while (res.size() != n) {
        int one = res.back();
        int f = 0;
        for (int i:g[one]) {
            vector<int> cur;
            set_intersection(all(g[one]), all(g[i]), back_inserter(cur));
            // cout << cur.size() << endl;
            if (cur.size() == 2 && !used[i]) {
                used[i] = 1;
                f = 1;
                res.pb(i);
                break;
            }
        }
        if (!f)
            return cout << -1, 0;
        // cout << res.size();
        // return 0;
    }

    for (int x:res)
        cout << x << ' ';
    return 0;
}