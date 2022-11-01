// hloya template v20
 
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
 
//clock_t start_time = clock();
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

int a[maxn];
vector<int> v[maxn];

int main() {
    //files1;
    int n, t, k;
    read(n, t, k);

    v[0].pb(0);
    int sz = 1;

    int x = 0;
    for (int i = 1; i <= t; i++) {
        read(a[i]);

        for (int j = 0; j < a[i]; j++) {
            v[i].pb(sz++);
        }

        x += max(a[i - 1] - a[i], 0);
        if (i == t)
            x += a[i];
    }
    if (x > k)
        bad("-1");

    set<pair<int, int> > e;
    for (int i = 0; i < v[1].size(); i++) {
        e.insert(mp(0, v[1][i]));
    }
    // return 0;
    for (int i = 1; i + 1 <= t; i++) {
        if (v[i].size() > v[i + 1].size()) {
            for (int j = 0; j < v[i + 1].size(); j++) {
                if (x < k && j) {
                    e.insert(mp(v[i][0], v[i + 1][j]));
                    x++;
                } else {
                    e.insert(mp(v[i][j], v[i + 1][j]));
                }
            }
        } else {
            for (int j = 0; j < v[i + 1].size(); j++) {
                if (j >= v[i].size()) {
                    e.insert(mp(v[i][0], v[i + 1][j]));
                    continue;
                }
                if (x < k && j) {
                    e.insert(mp(v[i][0], v[i + 1][j]));
                    x++;
                } else {
                    e.insert(mp(v[i][j], v[i + 1][j]));
                }
            }
        }
    }

    if (x != k) {
        cout << "-1";
    } else {
        cout << n << endl;
        for (auto E:e) {
            cout << E.f + 1 << ' ' << E.s + 1 << endl;
        }
    }
    return 0;
}