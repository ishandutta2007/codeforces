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

const int inf = 2e9 + 20;
const long double eps = 1e-12;
const int maxn = 1e6 + 12, base = 1e9 + 7;
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

ll cnt[101][101];;

int main() {
    int n, m;
    
    ll k;
    int x, y;
    cin >> n >> m >> k >> x >> y;

    if (n == 1) {
        ll ask = k / m;
        k %= m;
        ll mx = -1, mn = llinf;

        for (int j = 1; j <= m; j++) {
            cnt[1][j] = ask;
            if (k > 0) cnt[1][j]++;
            k--;
            amin(mn, cnt[1][j]), amax(mx, cnt[1][j]);
        }

        cout << mx << ' ' << mn << ' ' << cnt[x][y] << endl;
        return 0;
    }

    ll ask = (k / (n * m + (n - 2) * m));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (i == 1 || i == n)
                cnt[i][j] = ask;
            else
                cnt[i][j] = 2 * ask;
    k %= (n * m + (n - 2) * m);
    int go = 0;
    int pos = 1;

    while (k > 0) {
        for (int j = 1; j <= m && k > 0; j++) {
            cnt[pos][j]++;
            k--;
        }

        if (go == 0) pos++;
        else pos--;

        if (pos == 1 || pos == n) {
            go ^= 1;
        }
    }

    ll mx = -1, mn = llinf;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            amin(mn, cnt[i][j]), amax(mx, cnt[i][j]);
    cout << mx << ' ' << mn << ' ' << cnt[x][y] << endl;
    return 0;
}