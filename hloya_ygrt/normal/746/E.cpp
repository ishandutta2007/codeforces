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

vector<int> kc, kn, nc, nn;
int a[maxn], ans[maxn];
set<int> used;

int main() {
    int n, m;
    //files1;
    read(n, m);

    int lish = 0;
    map<int, int> place;

    for (int i = 0; i < n; i++) {
        read(a[i]);
        place[a[i]] = i;
        if (used.count(a[i]))
            lish++;
        else {
            if (a[i] % 2 == 0)
                kc.pb(a[i]);
            else
                kn.pb(a[i]);
            used.insert(a[i]);
        }
    }

    for (int i = 2; i <= m && nc.size() < maxn; i += 2)
        if (!used.count(i))
            nc.pb(i);
    for (int i = 1; i <= m && nn.size() < maxn; i += 2)
        if (!used.count(i))
            nn.pb(i);

    int res = 0;
    while (kc.size() > n / 2) {
        if (nn.empty())
            bad("-1");
        res++;
        int newN = nn.back();
        nn.pop_back();
        kc.pop_back();
        kn.pb(newN);
    }

    while (kn.size() > n / 2) {
        if (nc.empty())
            bad("-1");
        res++;
        int newC = nc.back();
        nc.pop_back();
        kn.pop_back();
        kc.pb(newC);
    }

    while (kc.size() < n / 2) {
        if (lish == 0 || nc.empty())
            bad("-1");
        lish--;
        res++;
        int newC = nc.back();
        nc.pop_back();
        kc.pb(newC);
    }

    while (kn.size() < n / 2) {
        if (lish == 0 || nn.empty())
            bad("-1");
        lish--;
        res++;
        int newN = nn.back();
        nn.pop_back();
        kn.pb(newN);
    }

    for (int i = 0; i < n; i++)
        ans[i] = -1;
    vector<int> any;
    for (int i:kc) {
        if (place.count(i))
            ans[place[i]] = i;
        else
            any.pb(i);
    }
    for (int i:kn) {
        if (place.count(i))
            ans[place[i]] = i;
        else
            any.pb(i);
    }

    printf("%d\n", res);
    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            ans[i] = any.back();
            any.pop_back();
        }
        printf("%d ", ans[i]);
    }
    return 0;
}