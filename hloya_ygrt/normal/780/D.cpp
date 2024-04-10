#include <bits/stdc++.h>

using namespace std;

bool dbg = 0;

clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("out1.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
#define ld long double
#define pii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define endl '\n'

void bad(string mes = "Impossible"){cout << mes;exit(0);}

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


const int inf = 1e9 + 20;
const int maxn = 1e3 + 12, base = 1e9 + 7;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const ll llinf = 2e18 + 5;

template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }

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

string f[maxn], s[maxn];
int cur[maxn];

bool good;

int n;

string name(int guy, int type) {
    if (type == 0)
        return f[guy];
    else
        return s[guy];
}

vector<int> kek;
void dfs(int v, int c) {
    cur[v] = c;
    kek.pb(v);

    for (int i = 0; i < n && good; i++) {
        if (i == v) continue;
        if (cur[i] != -1 && name(v, c) == name(i, cur[i])) {
            good = 0;
            break;
        }
        if (cur[i] != -1) {
            if (c == 0 && cur[i] == 1 && name(v, 0) == name(i, 0)) {
                good = 0;
                break;
            }
            if (c == 1 && cur[i] == 0 && name(v, 0) == name(i, 0)) {
                good = 0;
                break;
            }
        }
        if (cur[i] == -1) {
            int can0 = 1;
            if (name(v, c) == name(i, 0))
                can0 = 0;
            if (c == 1 && name(v, 0) == name(i, 0))
                can0 = 0;

            int can1 = 1;
            if (name(v, c) == name(i, 1))
                can1 = 0;
            if (c == 0 && name(v, 0) == name(i, 0))
                can1 = 0;

            if (can0 && can1) continue;
            if (!can0 && !can1) {
                good = 0;
                break;
            }

            if (can0)
                dfs(i, 0);
            else
                dfs(i, 1);
        }
    }
}

void clr() {
    for (int i : kek)
        cur[i] = -1;
    kek.clear();
}

bool brt() {

    for (int i = 0; i < (1 << n); i++) {
        bool good = 1;
        for (int j = 0; j < n; j++)
            for (int k = j + 1; k < n; k++) {
                int b1 = i & (1 << j);
                if (b1 != 0) b1 = 1;

                int b2 = i & (1 << k);
                if (b2 != 0) b2 = 1;

                if (name(j, b1) == name(k, b2))
                    good = 0;
                if ((b1 ^ b2) && name(j, 0) == name(k, 0))
                    good = 0;
            }
        if (good) {
            return 1;
        }
    }
    return 0;
}

bool solve() {
    memset(cur, -1, sizeof(cur));
    for (int i = 0; i < n; i++) {
        if (cur[i] == -1) {
            kek.clear();
            good = 1;
            dfs(i, 0);
            if (!good) {
                clr();
                good = 1;
                dfs(i, 1);
                if (!good)
                    bad("NO");
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++)
        if (cur[i])
            cout << s[i] << endl;
        else
            cout << f[i] << endl;
}

string rng() {
    string s;
    for (int i = 0; i < 3; i++)
        s += char('A' + rand() % 3);
    return s;
}

void gen() {
    ofstream cout("input.txt");
    int n = rand() % 5 + 1;
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        string f1 = rng();
        string f2 = rng();
        cout << f1 << ' ' << f2 << endl;
    }
}

void read() {
//    ifstream cin("input.txt");
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        f[i] = s.substr(0, 3);
        ::s[i] = s.substr(0, 2) + t.substr(0, 1);
    }
}

int main() {
    read();
    solve();
//    srand(time(0));
//    while (1) {
//        gen();
//        read();
//
//        if (solve() != brt())
//            exit(228);
//    }


//    for (int i = 0; i < n; i++)
//        if (cur[i])
//            cout << s[i] << endl;
//        else
//            cout << f[i] << endl;
    return 0;
}