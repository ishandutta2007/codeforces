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
const int maxn = 1e2 + 12, base = 1e9 + 7;
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

bool check1(pii a, pii b, pii c) {
    return 1ll * a.f * (b.s - c.s) + 1ll * b.f * (c.s - a.s) + 1ll * c.f * (a.s - b.s) < 0;
}

bool check2(pii a, pii b, pii c) {
    return 1ll * a.f * (b.s - c.s) + 1ll * b.f * (c.s - a.s) + 1ll * c.f * (a.s - b.s) > 0;
}

void convex_hull(vector<pii> &v) {
    vector<pii> down, up;
    sort(v.begin(), v.end());
    pii a = v[0], b = v[v.size() - 1];
    down.push_back(a);
    up.push_back(a);

    for(int i = 1; i < (int) v.size(); i++) {
        if(i == (int) v.size() - 1 || check1(a, v[i], b)) {
            while(up.size() >= 2 && !check1(up[up.size() - 2], up[up.size() - 1], v[i]))
                up.pop_back();
            up.push_back(v[i]);
        }
        if(i == (int) v.size() - 1 ||check2(a, v[i], b)) {
            while(down.size() >= 2 && !check2(down[down.size() - 2], down[down.size() - 1], v[i]))
                down.pop_back();
            down.push_back(v[i]);
        }
    }
    v.clear();
    for(int i = 0; i < (int) up.size(); i++)
        v.push_back(up[i]);
    for(int i = down.size() - 2; i > 0; i--)
        v.push_back(down[i]);
}

bool eq(ld a, ld b) {
    return abs(a - b) < eps;
}

int zn(ld x) {
    if (x > eps)
        return 1;
    if (x < -eps)
        return -1;
}

int main() {
    vector<pii> pt;
    int n, p, q;
    //files1;
    read(n, p, q);

    for (int i = 0; i < n; i++) {
        int a, b;
        read(a, b);
        pt.pb(mp(a, b));
        pt.pb(mp(a, 0));
        pt.pb(mp(0, b));
    }

    convex_hull(pt);

    ld k = (ld)q / p;

    ld ans = 0;

    for (int i = 0; i < pt.size(); i++) {
        if (eq((ld)k * pt[i].f, (ld)pt[i].s))
            amax(ans, (ld)pt[i].f);
    }

    for (int i = 0; i < pt.size(); i++) {
        pii cur = pt[i], nxt = pt[(i + 1) % (int)pt.size()];
        int one = zn((ld)k * cur.f - (ld)cur.s);
        int mone = zn((ld)k * nxt.f - (ld)nxt.s);
        if (mp(min(one, mone), max(one, mone)) != mp(-1, 1))
            continue;

        if (cur.f == nxt.f) {
            amax(ans, (ld)cur.f);
            continue;
        }

        ld k2 = (ld)(cur.s - nxt.s) / (ld)(cur.f - nxt.f);
        ld b2 = (ld)cur.s - (ld)k2 * cur.f;

        ld cur_pt = b2 / (k - k2);
        amax(ans, cur_pt);
    }

    ld cur_x = ans;
    ld cur_y = cur_x * k;

    // cout << k ;

    cout << fixed << setprecision(20) << max((ld)p / cur_x, (ld)q / cur_y);
    return 0;
}