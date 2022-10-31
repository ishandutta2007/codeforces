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

// clock_t start_time = clock();
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
const long double eps = 1e-12;
const int maxn = 1e5 + 12, base = 1e9 + 7;
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

struct pt {
    int x, y, id;
    pt(){}
    pt(int x, int y, int id):x(x), y(y), id(id) {}
};

bool cmp_x(pt & a, pt & b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp_y(pt & a, pt & b) {
    return a.y < b.y;
}

pt a[maxn], r[maxn];
pt ans1, ans2;
int dist;

int sqr(int x) { return x * x; }
void upd(pt& a, pt& b) {
    int curDist = sqr(a.x - b.x) + sqr(a.y - b.y);
    if (curDist < dist) {
        dist= curDist;
        ans1 = a;
        ans2 = b;
    }
}

pt t[maxn];

void solve(int l, int r) {
    if (l == r)
        return;
    int m = (l + r) >> 1;
    int midx = a[m].x;

    solve(l, m);
    solve(m + 1, r);

    merge(a + l, a + m + 1, a + m + 1, a + r + 1, t, cmp_y);
    copy(t, t + r - l + 1, a + l);

    int sz = 0;
    for (int i = l; i <= r; i++) {
        if (abs(a[i].x - midx) < dist) {
            for (int j = sz - 1; j >= 0 && abs(a[i].y - t[j].y) < dist; j--)
                upd(a[i], t[j]);
            t[sz++] = a[i];
        }
    }
}

int sign(int x) {
    return x >= 0 ? 1 : -1;
}

int main() {
    files;
    int n;
    read(n);

    for (int i = 0; i < n; i++) {
        int x, y;
        read(x, y);
        r[i] = pt(x, y, i);

        if (x >= 0 && y >= 0)
            a[i] = pt(+x, +y, i);
        else if (-x >= 0 && y >= 0)
            a[i] = pt(-x, +y, i);
        else if (x >= 0 && -y >= 0)
            a[i] = pt(+x, -y, i);
        else if (-x >= 0 && -y >= 0)
            a[i] = pt(-x, -y, i);
    }

    dist = inf;

    sort(a, a + n, cmp_x);
    solve(0, n - 1);

    int k1 = 0;
    int id1 = ans1.id;
    if (sign(r[id1].x) != sign(ans1.x))
        k1 |= 1;
    if (sign(r[id1].y) != sign(ans1.y))
        k1 |= 2;
    cout << id1 + 1 << ' ' << k1 + 1 << ' ';
    
    ans2.x *= -1;
    ans2.y *= -1;

    int k2 = 0;
    int id2 = ans2.id;
    if (sign(r[id2].x) != sign(ans2.x))
        k2 |= 1;
    if (sign(r[id2].y) != sign(ans2.y))
        k2 |= 2;
    cout << id2 + 1 << ' ' << k2 + 1 << ' ';
    return 0;
}