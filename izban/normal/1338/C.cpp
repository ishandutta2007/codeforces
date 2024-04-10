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

ll slow(ll n) {
    set<ll> st;
    vector<ll> a;

    ll x = 1;
    while ((int)a.size() < n) {
        while (st.find(x) != st.end()) x++;

        ll y = x + 1;
        while (st.find(y) != st.end() || st.find(x ^ y) != st.end()) y++;

        assert(x < y && y < (x ^ y));
        a.push_back(x);
        a.push_back(y);
        a.push_back(x ^ y);
        st.insert(x);
        st.insert(y);
        st.insert(x ^ y);
    }
    return a[n - 1];
}

const int a[2][4] = {
        {0, 2, 3, 1},
        {0, 3, 1, 2}
};

ll solve(int t, ll id, ll all) {
    if (all == 1) {
        return 0;
    }
    ll nall = all / 4;
    return a[t][id / nall] * nall + solve(t, id % nall, nall);
}

ll fast(ll n) {
    ll k = 1;
    while (k * 4 <= n) {
        k *= 4;
    }
    if ((n - k) % 3 == 0) {
        return k + (n - k) / 3;
    }
    if ((n - k) % 3 == 1) {
        return k + k + solve(0, (n - k) / 3, k);
    }
    return k + k + k + solve(1, (n - k) / 3, k);
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    if (0) {
        for (int i = 1; i <= 300; i++) {
            ll ans1 = fast(i);
            ll ans2 = slow(i);
            db3(i, ans1, ans2);
            if (ans1 != ans2) {
                db3(i, ans1,ans2);
                exit(0);
            }
        }
        return 0;
    }

    int T;
    scanf("%d", &T);
    while (T--) {
        ll n;
        scanf("%lld", &n);

        printf("%lld\n", fast(n));
    }

    return 0;
}