// hloya template v18

#include <bits/stdc++.h>
#include <valarray>
using namespace std;

bool dbg = 0;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define ll long long
// #define ld long double
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
const double eps = 1e-9;
const int maxn = 1e5 + 10, base = 1e9 + 7;
const ll llinf = 1e18 + 5;

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

map<pii, pii> sot;
void add(pii ab, pii c) {
    if (!sot.count(ab))
        sot[ab] = c;
    else
        sot[ab] = max(sot[ab], c);
}

int main() {
    int n;
    read(n);

    pair<int, pii> ans = mp(0, mp(-1, -1));

    for (int i = 0; i < n; i++) {
        int ar[3];
        for (int j = 0; j < 3; j++)
            read(ar[j]);
        sort(ar, ar + 3);
        ans = max(ans, mp(ar[0], mp(i, i)));

        for (int j = 0; j < 3; j++)
            for (int k = j + 1; k < 3; k++) {
                if (sot.count(mp(ar[j], ar[k]))) {
                    pii res = sot[mp(ar[j], ar[k])];
                    int cur = min(ar[j], res.f + ar[3 - j - k]);
                    int pos = res.s;
                    ans = max(ans, mp(cur, mp(pos, i)));
                }
            }
        for (int j = 0; j < 3; j++) {
            for (int k = j + 1; k < 3; k++) {
                add(mp(ar[j], ar[k]), mp(ar[3 - j - k], i));
            }
        }
    }

    if (ans.s.f == ans.s.s)
        cout << 1 << endl << ans.s.f + 1;
    else
        cout << 2 << endl << ans.s.f + 1 << ' ' << ans.s.s + 1;
    return 0;
}