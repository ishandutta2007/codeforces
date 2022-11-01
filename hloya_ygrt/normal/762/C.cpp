// hloya template v23

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

int fl[maxn], fr[maxn];
string a, b;

bool ok(int l, int r) {
    if (l == 0 && r == b.size() - 1) return 1;
    if (l == 0) {
        return fr[r + 1] != -1;
    }
    if (r == b.size() - 1) {
        return fl[l - 1] != a.size();
    }
    return fl[l - 1] < fr[r + 1];
}

int main() {
    cin >> a >> b;

    for (int i = 0, j = 0; i < b.size(); i++) {
        while (j < a.size() && a[j] != b[i]) j++;
        fl[i] = j;
        if (j != a.size()) j++;
    }

    for (int i = b.size() - 1, j = a.size() - 1; i >= 0; i--) {
        while (j >= 0 && a[j] != b[i]) j--;
        fr[i] = j;
        if (j != -1) j--;
    }

    if (fl[b.size() - 1] != a.size())
        bad(b);

    // cout << ok(0, )

    int ans_len = 0, pr, suf;
    for (int i = 0; i < b.size(); i++) {
        int l = i, r = b.size() - 1;
        while (l < r) {
            int m = (l + r) >> 1;
            if (ok(i, m))
                r = m;
            else
                l = m + 1;
        }
        if (ok(i, l) && (int)b.size() - (l - i + 1) > ans_len) {
            ans_len = (int)b.size() - (l - i + 1);
            pr = i - 1;
            suf = l + 1;
        }
    }
    if (ans_len == 0)
        bad("-");
    else {
        string res = "";
        for (int i = 0; i <= pr; i++)
            res += b[i];
        for (int i = suf; i < b.size(); i++)
            res += b[i];
        cout << res;
    }
    return 0;
}