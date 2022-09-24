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

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
            p[i]--;
        }


        vector<int> rev(n);
        for (int i = 0; i < n; i++) rev[p[i]] = i;

        set<int> alive;
//        alive.insert(-1);
        vector<int> cnt(n, 1);

        set<pair<int, int>> mx;
        for (int i = 0; i < n; i++) {
            alive.insert(i);
            mx.insert({cnt[i], i});
        }

        bool ok = 1;
        for (int i = 0; i < n; i++) {
            ok &= cnt[rev[i]] == mx.rbegin()->first;

            alive.erase(rev[i]);
            auto nxt = alive.lower_bound(rev[i]);
            mx.erase({cnt[rev[i]], rev[i]});
            if (nxt != alive.end()) {
                int j = *nxt;
                mx.erase({cnt[j], j});
                cnt[j] += cnt[rev[i]];
                mx.insert({cnt[j], j});
            }
        }
        string res = (ok ? "Yes" : "No");
        printf("%s\n", res.c_str());
    }

    return 0;
}