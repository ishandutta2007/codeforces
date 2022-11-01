// hloya template v20

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

void reads(string & s) {
    string ans = "";
    char c = endl;
    while (c == endl || c == ' ')
        c = getchar();
    while (c != endl && c != ' ' && c)
        ans += c, c = getchar();
    s = ans;
}

const int inf = 1e9;
const long double eps = 1e-12;
const int maxn = 5e5 + 10, base = 1e9 + 7;
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

int a[maxn], res[maxn];
vector<pii> q[maxn];
int tree[maxn];
int n;

int mn(int r) {
    int res = inf;
    while (r) {
        res = min(res, tree[r]);
        r -= r & -r;
    }
    return res;
}

void upd(int pos, int val) {
    while (pos <= n) {
        tree[pos] = min(tree[pos], val);
        pos += pos & -pos;
    }
}

int main() {
    int m;
    read(n, m);

    for (int i = 0; i < n; i++)
        read(a[i]);

    for (int i = 0; i < m; i++) {
        int l, r;
        read(l, r);
        l--, r--;
        q[l].pb(mp(r, i));
    }

    for (int i = 1; i <= n; i++) {
        tree[i] = inf;
    }

    map<int, int> lst;

    for (int i = n - 1; i >= 0; i--) {
        int cur = a[i];
        if (lst.count(cur)) {
            int j = lst[cur];
            upd(j + 1, j - i);
        }
        lst[cur] = i;

        for (auto e:q[i]) {
            int r = e.f, it = e.s;
            res[it] = mn(r + 1);
        }
    }

    for (int i = 0; i < m; i++)
        printf("%d\n", res[i] == inf ? -1 : res[i]);
    return 0;
}