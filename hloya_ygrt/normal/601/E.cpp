#include <bits/stdc++.h>
#include <valarray>

using namespace std;
 

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
// template<typename ... T> void shit(T& ... x){}
// template<typename ... T> void dec(T& ... x){shit(--x...);}
// template<typename ... T> void inc(T& ... x){shit(++x...);}
 
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
 
template<typename T>
void read(T& a) {
    a = input<T>();
}
 
template<typename T>
void read(T& a, T& b) {
    read(a), read(b);
}
 
template<typename T>
void read(T& a, T& b, T& c) {
    read(a, b), read(c);
}
 
template<typename T>
void read(T& a, T& b, T& c, T& d) {
    read(a, b), read(c, d);
}
 
const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 5e4 + 10, base = 1e9 + 7;
const ll llinf = 1e18 + 1;
 
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

int k;
const int p = 1e7 + 19;
int pw[1005];

struct backpack {
    vector<vector<ll> > dp;
    backpack(){
        dp.push_back(vector<ll>(k + 1, 0));
    }

    void addItem(int c, int w) {
        dp.push_back(vector<ll>(k + 1, 0));
        for (int i = 1; i <= k; i++) {
            dp.back()[i] = max(dp[dp.size() - 2][i], (i - w >= 0) ? (dp[dp.size() - 2][i - w] + c) : -llinf);
        }
    }

    void remItem() {
        dp.pop_back();
    }

    int res() {
        int ans = 0;
        for (int i = 1; i <= k; i++) {
            ans += 1LL * dp.back()[i] * pw[i - 1] % base;
            if (ans >= base)
                ans -= base;
        }
        return ans;
    }
};

vector<pair<int, int> > tree[4 * maxn];

void modify(int v, int tl, int tr, int l, int r, int c, int w) {
    if (l > r)
        return;
    if (tl == l && tr == r) {
        tree[v].pb(mp(c, w));
        return;
    }
    int tm = (tl + tr) >> 1;
    modify(v << 1, tl, tm, l, min(r, tm), c, w);
    modify(v << 1|1, tm + 1, tr, max(l, tm + 1), r, c, w);
}

backpack* st;
void process(int v, int tl, int tr) {
    int need = 0;
    for (auto i:tree[v])
        if (i.f != -1)
            st->addItem(i.f, i.s);
        else
            need = 1;

    if (need)
        printf("%d\n", st->res());
    
    if (tl != tr) {
        int tm = (tl + tr) >> 1;
        process(v << 1, tl, tm);
        process(v << 1|1, tm + 1, tr);
    }

    for (int i = 0; i < tree[v].size() - need; i++)
        st->remItem();
}

vector<pair<int, int> > itm;
bool used[maxn];
int time_in[maxn];

int main() {
    int n;
    read(n, k);

    st = new backpack();

    pw[0] = 1;
    for (int i = 1; i < k; i++)
        pw[i] = (1LL * pw[i - 1] * p) % base;
    for (int i = 0; i < n; i++) {
        int c, w;
        read(c, w);
        itm.pb(mp(c, w));
    }

    int q;
    read(q);
    for (int i = 0; i < q; i++) {
        int type;
        read(type);

        if (type == 1) {
            int c, w;
            read(c, w);
            time_in[itm.size()] = i + 1;
            itm.pb(mp(c, w));
        }

        if (type == 2) {
            int x;
            read(x);
            x--;
            used[x] = 1;

            modify(1, 0, n + q, time_in[x], i + 1, itm[x].f, itm[x].s);
        }

        if (type == 3) {
            modify(1, 0, n + q, i + 1, i + 1, -1, -1);
        }
    }

    for (int i = 0; i < itm.size(); i++) {
        if (!used[i])
            modify(1, 0, n + q, time_in[i], n + q, itm[i].f, itm[i].s);
    }

    process(1, 0, n + q);
    return 0;
}