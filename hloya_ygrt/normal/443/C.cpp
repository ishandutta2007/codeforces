// hloya template v19

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

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("magic.out","w",stdout)
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

bool can(vector<pair<int, int> >& a, int cmask, int nmask) {
    int pairColor[5], pairNumber[5];
    for (int i = 0; i < 5; i++)
        pairColor[i] = -1, pairNumber[i] = -1;
    pair<int, int> unk = mp(-1, -1);
    
    for (int i = 0; i < a.size(); i++) {
        int c = -1, n = -1;
        if (cmask & (1<<a[i].f))
            c = a[i].f;
        if (nmask & (1<<a[i].s))
            n = a[i].s;
        
        if (c != -1 && n == -1) {
            if (pairColor[c] != -1 && pairColor[c] != a[i].s)
                return false;
            pairColor[c] = a[i].s;
        }
        if (n != -1 && c == -1) {
            if (pairNumber[n] != -1 && pairNumber[n] != a[i].f)
                return false;
            pairNumber[n] = a[i].f;
        }
        if (c == -1 && n == -1) {
            if (unk != mp(-1, -1) && unk != a[i])
                return false;
            unk = a[i];
        }
    }
    return true;
}

int main() {
    map<char, int> color;
    color['R'] = 0, color['G'] = 1, color['B'] = 2, color['Y'] = 3, color['W'] = 4;

    int n;

    fast_io;

    cin >> n;

    vector<pair<int, int> > tmp, unq;

    for (int i = 0; i < n; i++) {
        char C, N;
        cin >> C >> N;

        int b1 = color[C], b2 = N - '1';
        tmp.pb(mp(b1, b2));
    }

    sort(all(tmp));

    for (int i = 0; i < n; i++) {
        if (i == 0 || tmp[i] != tmp[i - 1]) {
            unq.pb(tmp[i]);
        }
    }

    int ans = inf;
    // can(unq, 7, 0);
    // return 0;

    for (int mask1 = 0; mask1 < (1 << 5); mask1++)
        for (int mask2 = 0; mask2 < (1 << 5); mask2++) {
            if (can(unq, mask1, mask2))
                ans = min(ans, __builtin_popcount(mask1) + 
                               __builtin_popcount(mask2));
        }
    cout << ans;
    return 0;
}