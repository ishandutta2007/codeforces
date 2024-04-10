#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
#include <random>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define db3(x, y, z) cerr << "(" << #x << ", " << #y << ", " << #z << ") = (" << x << ", " << y << ", " << z << ")\n"
#define dbv(a) cerr << #a << " = "; for (auto xxxx: a) cerr << xxxx << " "; cerr << endl


using namespace std;

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
    ~__timestamper(){
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");
#else
struct __timestamper {};
#endif

typedef long long ll;
typedef long double dbl;

const char SUM = '+';
const char XOR = '^';

struct op {
    ll x, y;
    char c;
};

void print(vector<op> v) {
    printf("%d\n", (int)v.size());
    for (auto o : v) {
        printf("%lld %c %lld\n", o.x, o.c, o.y);
    }
}

const int INF = 1e9;
vector<op> solve(int n) {
    if (n == 1) {
        return {};
    }

    mt19937 rnd(n);
    set<int> st;
    vector<int> vct;

    st.insert(0);
    st.insert(n);
    vct.push_back(n);

    vector<op> res;
    if (n <= 100) {
        const int Z = 25000;
        for (int i = 0; i < Z && i< (int)vct.size(); i++) {
            for (int j = 0; j <= i; j++) {
                int x = vct[i];
                int y = vct[j];

                for (char c : {SUM, XOR}) {
                    int nw = c == SUM ? (x + y) : (x ^ y);
                    if (nw > n * n) continue;

                    if (st.find(nw) == st.end()) {
                        if (vct.size() >= Z && nw != 1) continue;
                        st.insert(nw);
                        vct.push_back(nw);
                        res.push_back({x, y, c});
                        if (nw == 1) return res;
                    }
                }
            }
        }
        assert(0);
    }

    const int Z = 50;
    for (int i = 1; i < Z; i++) {
        res.push_back({n * i, n, SUM});
    }

    ll mn = 1e18;  vector<op> omn;
    ll mn0 = 1e18; vector<op> omn0;

    auto upd =[&](ll &cmn, vector<op> &cop, ll nmn, vector<op> nop) {
        if (nmn == 0) return;
        if (cmn > nmn) {
            cmn = nmn;
            cop = nop;
        }
    };

    for (int i = 1; i <= Z; i++) {
        for (int j = i + 1; j <= Z; j++) {
            ll x = i * n;
            ll y = j * n;
            ll z = x ^ y;
            if (z % 2 == 1) {
                upd(mn0, omn0, z ^ n, {{x, y, XOR}, {z, n, XOR}});
            } else {
                upd(mn0, omn0, z, {{x, y, XOR}});
            }
        }
    }
    for (auto t : omn0) res.push_back(t);

    for (int i = 0; i < 20; i++) {
        res.push_back({(1 << i) * mn0, (1 << i) * mn0, SUM});
        res.push_back({n, (1 << i) * mn0, SUM});
    }

    for (int i = 0; i < 20; i++) {
        upd(mn, omn, n ^ ((1 << i) * mn0), {{n, (1 << i) * mn0, XOR}});
        upd(mn, omn, (2 * n) ^ (n + ((1 << i) * mn0)), {{2 * n, n + (1 << i) * mn0, XOR}});
    }
    for (auto t : omn) res.push_back(t);
//    for (int i = 0; i < 20; i++) {
//        mn = min(mn, n ^ ((1 << i) * mn0));
//        mn = min(mn, (2 * n) ^ (n + ((1 << i) * mn0)));
//    }
//    for (int i = 1; i <= Z; i++) {
//        for (int j = i; j <= Z; j++) {
//            int x = i * n;
//            int y = j * n;
//            int z = x ^ (y + mn0);
//            if (z % 2 == 0) z ^= n;
//            z ^= mn0;
//            if (z % 2 == 1) mn = min(mn, z);
//        }
//    }

    dbv(st);
    db2(n, mn);
    db(mn0);
    if (!(n & (n + 1))) {

    } else {
        assert(mn * 2 < n);
    }

    auto v = solve(mn);
    res.insert(res.end(), v.begin(), v.end());
    return res;
}

vector<op> fast(ll n) {
    vector<op> res;

    auto gauss = [&res](vector<pair<ll, ll>> a, bool add_res) {
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        int k = 1;
        while ((1LL << k) < a[0].first) k++;

        for (int i = 0; i < k; i++) {
            int j = max_element(a.begin() + i, a.end()) - a.begin();
            swap(a[j], a[i]);

            ll bit = (1LL << (k - 1 - i));
            assert(a[i].first & bit);

            for (int j = i + 1; j < (int)a.size(); j++) {
                if (i == j) continue;
                if (a[j].first & bit) {
                    if (add_res) {
                        res.push_back({a[j].first, a[i].first, XOR});
                    }
                    a[j].first ^= a[i].first;
                }
            }
        }
        return a;
    };


    vector<pair<ll, ll>> a;
    for (int i = 1; i <= n * 3; i++) {
        a.push_back({i * n, i});
    }
    reverse(a.begin(), a.end());

    auto basis = gauss(a, false);
    vector<pair<ll, ll>> na;
    for (auto o : basis) {
        if (o.first != 0) {
            na.emplace_back(o.second * n, o.second);
        }
    }

    res.push_back({n, n, XOR});
    const int B = 25;
    for (int i = 0; i < B; i++) {
        res.push_back({(1LL << i) * n, (1LL << i) * n, SUM});
    }
    for (auto o : na) {
        ll cur = 0;
        ll x = o.second;
        for (int i = 0; i < B; i++) {
            if (x & (1 << i)) {
                res.push_back({cur * n, (1 << i) * n, SUM});
                cur += 1 << i;
            }
        }
//        db(cur * n);
    }

    gauss(na, true);

    return res;
}

void test() {
    fast(1e6 - 1);
    exit(0);
//    cerr << clock() / (double)CLOCKS_PER_SEC<< endl;
//    fast((1 << 7) - 1);
//    cerr << clock() / (double)CLOCKS_PER_SEC<< endl;
//    fast((1 << 17) - 1);
//    cerr << clock() / (double)CLOCKS_PER_SEC<< endl;
//    fast((1 << 19) - 1);
//    cerr << clock() / (double)CLOCKS_PER_SEC<< endl;
//    cerr << clock() / (double)CLOCKS_PER_SEC<< endl;

    int mx = 0;
    for (int n = 1; n <= 1e4; n += 2) {
        db2(n, mx);

        auto v = fast(n);
        set<int> st;
        st.insert(n);
        for (auto o : v) {
            if (o.c == XOR) {
//                db3(o.x, o.y, o.c);
            }
            assert(st.find(o.x) != st.end());
            assert(st.find(o.y) != st.end());
            if (o.c == SUM) {
                st.insert(o.x + o.y);
            } else {
                st.insert(o.x ^ o.y);
            }
        }
        assert(st.find(1) != st.end());
        assert(v.size() <= 1e5);
        mx = max(mx, (int)v.size());
    }
    fast(1e6 - 1);
    exit(0);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
//    test();

    int n;
    while (scanf("%d", &n) == 1) {
        print(fast(n));
    }

    return 0;
}