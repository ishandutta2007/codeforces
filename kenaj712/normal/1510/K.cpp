#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
    #define dbg(...)
#endif

#define st first
#define nd second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define len(x) ((int)(x).size())
#define low(x) ((x) & (-(x)))
#define forn(i, n) for (int i = 0; i < n; ++i)

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef string str;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<typename... Args>
void _dbg(const char* s, Args&&... args) {
    cerr << "[ " <<  s << " = ";
    ((cerr << std::forward<Args>(args) << ", "), ...);
    cerr << "]\n";
}

template<typename... Args>
void print(Args&&... args) {
    ((cout << std::forward<Args>(args) << " "), ...);
    cout << "\n";
}

template<typename T, typename Alloc>
std::ostream& operator<<(std::ostream& out, const std::vector<T, Alloc>& v) {
    bool isfirst = true;
    for (const auto& x : v) {
        if (!isfirst)
            out << ' ';
        else
            isfirst = false;
        out << x;
    }
    return out;
}

template<typename T, typename Alloc>
std::ostream& operator<<(std::ostream& out, const std::set<T, Alloc>& v) {
    bool isfirst = true;
    for (const auto& x : v) {
        if (!isfirst)
            out << ' ';
        else
            isfirst = false;
        out << x;
    }
    return out;
}

const int N = 2e3 + 7;
const int INF = 1e9;
int p[N], perm[N];
int h, n;

void op1() {
    for (int i = 0; i < n; i += 2)
        swap(perm[i], perm[i + 1]);
}

void op2() {
    for (int i = 0; i < h; ++i)
        swap(perm[i], perm[i + h]);
}

int solve() {
    scanf("%d", &h);
    n = 2 * h;
    forn (i, n)
        scanf("%d", &p[i]);

    if (is_sorted(p, p + n))
        return 0;

    copy(p, p + n, perm);
    int res = INF, steps = 0;

    do {
        op1(); ++steps;
        if (is_sorted(perm, perm + n)) {
            res = steps;
            break;
        }
        op2(); ++steps;
        if (is_sorted(perm, perm + n)) {
            res = steps;
            break;
        }
    } while (!equal(perm, perm + n, p));
    
    copy(p, p + n, perm);
    steps = 0; 

    do {
        op2(); ++steps;
        if (is_sorted(perm, perm + n)) {
            res = min(res, steps);
            break;
        }
        op1(); ++steps;
        if (is_sorted(perm, perm + n)) {
            res = min(res, steps);
            break;
        }
    } while (!equal(perm, perm + n, p));

    return res == INF ? -1 : res;
}

int main() {
    int t = 1;
    while (t--) {
        printf("%d\n", solve());
    }

    return 0;
}