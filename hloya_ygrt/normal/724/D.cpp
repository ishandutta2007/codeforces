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
const int maxn = 1e5 + 10, base = 1e9 + 7;
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

set<int> used;

pair<char, int> tree[4 * maxn];
string s;

void update(int v, int tl, int tr, int pos, char val) {
    if (tl == tr) {
        tree[v] = mp(val, -pos);
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
        update(v << 1, tl, tm, pos, val);
    else
        update(v<<1|1, tm + 1, tr, pos, val);
    tree[v] = min(tree[v<<1], tree[v<<1|1]);
}

pair<char, int> qu(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return mp('z' + 1, inf);
    if (tl == l && tr == r) {
        return tree[v];
    }
    int tm = (tl + tr) >> 1;
    return min(qu(v << 1, tl, tm, l, min(r, tm)),
            qu(v << 1 | 1, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
    //files1;
    int m;
    cin >> m >> s;
    int n = s.size();

    for (int i = 0; i < n; i++) {
        update(1, 0, n - 1, i, s[i]);
    }

    string res;
    for (int i = 0; i + m - 1 < n;) {
        int r = i + m - 1;
        auto x = qu(1, 0, n - 1, i, r);
        res += x.f;
        
        update(1, 0, n - 1, -x.s, 'z' + 1);

        i = -x.s + 1;
    }

    sort(all(res));

    string res2;
    for (int i = 0; i < n; i++) {
        char kek = qu(1, 0, n - 1, i, i).f;
        if (kek < res.back())
            res2 += kek;
    }

    res += res2;
    
    sort(all(res));
    cout << res;
    return 0;
}