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
const int maxn = 2e6 + 10;
ll base = (ll)1e12 + 7;
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

ll d[maxn], p = 29;
set<pair<ll, int> > bd;
map<pair<ll, int> , int> sot;

int mda[maxn];
bool good[maxn];

ll add(ll a, ll b) {
    return (a + b) % base;
}

ll mult(ll a, ll b) {
    ll ans = 0;
    while (b) {
        if (b % 2)
            ans = (ans + a) % base;
        a = (a + a) % base;
        b /= 2;
    }
   return ans;
}

int main() {
    //files1;
    d[0] = 1;
    for (int i = 1; i < maxn; i++)
        d[i] = mult(d[i - 1], p);

    ll cur_hash = 0;
    int n, k;
    read(n, k); 

    string s;
    reads(s);

    deque<int> window;
    s += s;

    for (int i = (int)s.size() - 1; i >= 0; i--) {
        if (window.size() == k) {
            int last = window.back();
            cur_hash = (1LL * cur_hash - mult(last, d[k - 1])) % base;
            if (cur_hash < 0)
                cur_hash += base;
            window.pop_back();
        }
        int curC = s[i] - 'a';
        cur_hash = mult(cur_hash, p);
        cur_hash = (1LL * cur_hash + 1LL * curC) % base;
        window.push_front(curC);

        // cout << curC << ' ';
        // cout << i << ' ' << cur_hash << endl;
        
        if (i < n * k) {
            int pos = i % k;
            int real_pos = i % (n * k);

            // cout << i - k + 1 << ' ' << i << ' ' << cur_hash << endl;

            if (bd.count(mp(cur_hash, pos)))
                continue;
            if (sot.count(mp(cur_hash, pos))) {
                sot.erase(mp(cur_hash, pos));
                bd.insert(mp(cur_hash, pos));
            } else {
                sot[mp(cur_hash, pos)] = real_pos;
            }
        }
    }
    int g;
    read(g);

    for (int i = 0; i < g; i++) {
        string t;
        reads(t);

        cur_hash = 0;
        for (int j = 0; j < k; j++) {
            int curC = t[j] - 'a';
            cur_hash = (1LL * cur_hash + mult(d[j], curC)) % base;
        }
        // cout << t << ' ';
        // cout << cur_hash << endl;
        for (int pos = 0; pos < k; pos++) {
            if (sot.count(mp(cur_hash, pos))) {
                int real_pos = sot[mp(cur_hash, pos)];
                mda[real_pos] = i + 1;
            }
        }
    }

    for (int i = 0; i < k; i++)
        good[i] = 1;

    for (int i = 0; i < n * k; i++) {
        if (mda[i] == 0)
            good[i % k] = 0;
    }

    for (int i = 0; i < k; i++) {
        if (good[i]) {
            puts("YES");
            for (int j = i; j < n * k; j += k) {
                printf("%d ", mda[j]);
            }
            exit(0);
        }
    }
    puts("NO");
    return 0;
}