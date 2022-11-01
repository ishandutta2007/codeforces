// hloya template v21

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
const int maxn = 2e5 + 12, base = 1e9 + 7;
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

vector<int> pos[maxn];

set<pair<int, int> > occ;

int main() {
    int n;
    read(n);

    for (int i = 0; i < n; i++) {
        int a, b;
        read(a, b);
        if (!pos[a].empty())
            occ.erase(mp(pos[a].back(), a));
        pos[a].pb(b);
        occ.insert(mp(b, a));
    }

    int q;
    read(q);

    vector<int> l;
    while (q--) {
        int k;
        read(k);
        l.resize(k);

        for (int i = 0; i < k; i++) {
            read(l[i]);
            if (!pos[l[i]].empty())
                occ.erase(mp(pos[l[i]].back(), l[i]));
        }

        if (occ.empty()) {
            puts("0 0");
        } else
        if (occ.size() == 1) {
            int x = occ.begin()->s;
            printf("%d %d\n", x, pos[x][0]);
        } else {
            int x = (--occ.end())->s;
            int bound = (--(--occ.end()))->f;
            printf("%d %d\n", x, *lower_bound(all(pos[x]), bound));
        }

        for (int i = 0; i < k; i++) {
            if (!pos[l[i]].empty())
                occ.insert(mp(pos[l[i]].back(), l[i]));
        }
    }
    return 0;
}