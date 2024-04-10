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
const int maxn = 5e3 + 12, base = 1e9 + 7;
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

ll curDelta[maxn], a[maxn];

pair<int, pair<int, int> > query[maxn];
int type_q[maxn];

int main() {
    //files1;
    int n, m;
    read(n, m);

    for (int i = 0; i < n; i++)
        a[i] = llinf;

    for (int i = 0; i < m; i++) {
        int type;
        read(type);

        type_q[i] = type;

        if (type == 1) {
            int l, r, d;
            read(l, r, d);
            l--, r--;
            query[i] = mp(d, mp(l, r));

            for (int j = l; j <= r; j++)
                curDelta[j] += d;
        } else {
            int l, r, m;
            read(l, r, m);
            l--, r--;
            query[i] = mp(m, mp(l, r));

            for (int j = l; j <= r; j++)
                amin(a[j], m - curDelta[j]);
        }
    }

    memset(curDelta, 0, sizeof(curDelta));

    for (int i = 0; i < n; i++) {
        if (a[i] == llinf)
            a[i] = -(int)1e9;
        if (abs(a[i]) > (ll)1e9)
            bad("NO");
    }
    for (int i = 0; i < m; i++) {
        int type = type_q[i];

        if (type == 1) {
            int l, r, d;
            l = query[i].s.f, r = query[i].s.s;
            d = query[i].f;

            for (int j = l; j <= r; j++)
                curDelta[j] += d;
        } else {
            int l, r, m;
            l = query[i].s.f, r = query[i].s.s;
            m = query[i].f;

            ll realMax = -llinf;
            for (int j = l; j <= r; j++)
                amax(realMax, a[j] + curDelta[j]);
            if (realMax != (ll)m)
                bad("NO");
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}