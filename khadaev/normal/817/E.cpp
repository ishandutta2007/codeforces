#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

template<typename T>
inline void setmax(T& a, T b) {
    if (a < b) a = b;
}

template<typename T>
inline void setmin(T& a, T b) {
    if (a > b) a = b;
}

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int BITS = 27;
struct Trie {
    vector<int> go[2], sum;

    Trie () {
        go[0] = {-1}, go[1] = {-1}, sum = {0};
    }

    void add(int x) {
        int pos = 0;
        ford(i, 0, BITS) {
            ++sum[pos];
            int& cur = go[(x >> i) & 1][pos];
            if (cur == -1) {
                cur = (int)sum.size();
                go[0].eb(-1);
                go[1].eb(-1);
                sum.eb(0);
            }
            pos = go[(x >> i) & 1][pos];
        }
        ++sum[pos];
    }

    void rem(int x) {
        int pos = 0;
        ford(i, 0, BITS) {
            --sum[pos];
            pos = go[(x >> i) & 1][pos];
        }
        --sum[pos];
    }

    int get(int x, int l) {
        int pos = 0, ans = 0;
        ford(i, 0, BITS) {
            if ((l >> i) & 1) {
                int less = go[(x >> i) & 1][pos];
                if (less != -1) 
                    ans += sum[less];
            }
            pos = go[((x ^ l) >> i) & 1][pos];
            if (pos == -1) break;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    srand((unsigned)chrono::high_resolution_clock::now().time_since_epoch().count());
    int n;
    cin >> n;
    Trie T;
    while (n--) {
        int tp, p;
        cin >> tp >> p;
        if (tp == 1) T.add(p);
        else if (tp == 2) T.rem(p);
        else {
            int l;
            cin >> l;
            cout << T.get(p, l) << '\n';
        }
    }
}