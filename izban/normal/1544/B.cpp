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


int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        auto gen = [&](int n, int m, int s) {
            vector<string> a(n, string(m, '0'));
            vector<pair<int, int>> pos;
            for (int j = 0; j < m - 1; j++) {
                pos.push_back({0, j});
            }
            for (int i = 0; i < n - 1; i++) {
                pos.push_back({i, m - 1});
            }
            for (int j = m - 1; j > 0; j--) {
                pos.push_back({n - 1, j});
            }
            for (int i = n - 1; i > 0; i--) {
                pos.push_back({i, 0});
            }

            vector<pair<int, int>> taken;
            for (int i = s; i < (int)pos.size(); i++) {
                auto p = pos[i];
                bool bad = 0;
                for (auto o : taken) {
                    if (max(abs(p.first - o.first), abs(p.second - o.second)) <= 1) {
                        bad = 1;
                        break;
                    }
                }
                if (!bad) {
                    taken.push_back(p);
                    a[p.first][p.second] = '1';
                }
            }
            return a;
        };

        auto cnt = [&](vector<string> a) {
            int res = 0;
            for (auto s : a) {
                for (char c : s) {
                    res += c == '1';
                }
            }
            return res;
        };

        int n, m;
        cin >> n >> m;

        vector<string> ans;
        for (int k = 0; k < 3; k++) {
            auto cur = gen(n, m, k);
            if (cnt(cur) > cnt(ans)) {
                ans = cur;
            }
        }
        for (int i = 0; i < n; i++) cout << ans[i] << endl;
        cout << endl;
    }

    return 0;
}