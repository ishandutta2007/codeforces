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
typedef long double ld;

vector<pair<int*, int>> vct;
void Set(int &x, int y) {
    vct.emplace_back(&x, x);
    x = y;
};

    const int MX = 1 << 20;
    vector<int> pos(MX + 1, -1);


ll solve(int n, int k, vector<int> a) {
    int m = 1 << n;

    auto get = [&](int i) {
        if (i < (int)a.size()) return a[i];
        return 0;
    };

    auto b = a;
    b.erase(b.begin());
    sort(b.begin(), b.end());

    for (int i = 1; i < m; i++) pos[a[i]] = i;

    int zero = -1;
    function<void(int, bool)> f = [&](int i, bool change) {
        int l = i * 2;
        int r = i * 2 + 1;
        if (get(l) == 0 && get(r) == 0) {
            if (change) {
                a[i] = 0;
            }
            zero = i;
        } else {
            if (get(l) > get(r)) {
                if (change) {
                    a[i] = get(l);
                    pos[a[i]] = i;
                }
                f(l, change);
            } else {
                if (change) {
                    a[i] = get(r);
                    pos[a[i]] = i;
                }
                f(r, change);
            }
        }
    };

    vector<int> ans;
    int ccur = b.size() - 1;
    for (int i = 0; i < ((1 << n) - (1 << k)); i++) {
        while (1) {
            int cur = b[ccur];
            if (pos[cur] < 0) {
                ccur--;
                continue;
            }

            f(pos[cur], false);
            if (zero < (1 << k)) {
                ccur--;
            } else {
                ans.push_back(pos[cur]);
                f(pos[cur], true);
                pos[cur] = -1;
                ccur--;
                break;
            }
        }
    }



    ll sum =0;
    for (int x : a) sum += x;

    printf("%lld\n", sum);
    for (int x : ans) {
        printf("%d ", x);
    }
    printf("\n");

    return sum;
}

void stress() {
    for (int it = 13;; it++) {
        db(it);

        mt19937 rnd(it);
//        int n = rnd() % 10 + 2;
        int n = 20;
        int k = rnd() % n + 1;

        vector<int> a(1 << n);
        iota(a.begin(), a.end(), 0);
        shuffle(a.begin() + 1, a.end(), rnd);
        solve(n, k, a);
    }
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
//    stress();

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> a(1 << n);
        for (int i =1; i < (1 << n); i++) scanf("%d", &a[i]);

        solve(n, k, a);
    }

    return 0;
}