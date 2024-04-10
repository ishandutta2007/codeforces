// hloya template v19

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
const int maxn = 2e5 + 10, base = 1e9 + 7;
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

ll cur[maxn];
ll c[maxn], b[maxn];
ll ans[maxn];

int cntWithByte[1000];

void checkAnd(int n) {
    for (int i = 0; i < n; i++) {
        ll realB = 0;
        ll num = ans[i];

        for (int j = 0; num && realB < b[i]; j++) {
            if (num % 2) {
                realB += 1LL * cntWithByte[j] * (1LL << j);
            }
            num /= 2LL;
        }

        if (realB != b[i]) {
            bad("-1");
        }
    }
}

void checkOr(int n) {
    for (int i = 0; i < n; i++) {
        ll realC = 0;
        ll num = ans[i];

        for (int j = 0; realC < c[i] && j <= 60; j++) {
            if (num % 2) {
                realC += 1LL * n * (1LL << j);
            } else {
                realC += 1LL * cntWithByte[j] * (1LL << j);
            }
            num /= 2LL;
        }

        if (realC != c[i]) {
            bad("-1");
        }
    }
}

int main() {
    int n;
    read(n);

    for (int i = 0; i < n; i++)
        read(b[i]);
    ll allSum = 0;
    for (int j = 0; j < n; j++) {
        read(c[j]);
        cur[j] = b[j] + c[j];

        allSum += cur[j];
    }
    if (allSum % (2LL * n))
        bad("-1");
    ll numSum = allSum / (2LL * n);

    for (int i = 0; i < n; i++) {
        ll num = cur[i] - numSum;
        if (num % n)
            bad("-1");
        num /= n;
        ans[i] = num;
        if (ans[i] > c[i])
            bad("-1");

        for (int j = 0; num; j++) {
            if (num % 2) {
                cntWithByte[j]++;
            }
            num /= 2;
        }
    }
    checkAnd(n);
    checkOr(n);
    for (int i = 0; i < n; i++)
        printf("%lld ", ans[i]);
    return 0;
}