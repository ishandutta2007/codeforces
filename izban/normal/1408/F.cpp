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

vector<pair<int, int>> solve(int n) {
    vector<pair<int, int>> ans;

    function<void(vector<int>)> rec = [&](vector<int> v) {
        if (v.size() == 1) {
            return;
        }

        assert(v.size() % 2 == 0);
        vector<int> v1, v2;
        for (int i = 0; i + 1 < (int)v.size(); i += 2) {
            v1.push_back(v[i]);
            v2.push_back(v[i + 1]);
        }
        rec(v1);
        rec(v2);

        for (int i = 0; i < (int)v1.size(); i++) {
            ans.push_back({v1[i], v2[i]});
        }
    };
    int cur = 1;
    vector<vector<int>> v;
    for (int i = 30; i >= 0; i--) {
        if (n & (1 << i)) {
            vector<int> cv;
            for (int j = 0; j < (1 << i); j++) {
                cv.push_back(cur++);
            }
            rec(cv);
            v.push_back(cv);
        }
    }

    while (v.size() > 2) {
        if (v[(int)v.size() - 1].size() == v[(int)v.size() - 2].size()) {
            auto v1 = v.back();
            v.pop_back();
            auto v2 = v.back();
            v.pop_back();
            int k = v1.size();
            for (int i = 0; i < k; i++) {
                v1.push_back(v2[i]);
                ans.push_back({v1[i], v2[i]});
            }
            v.push_back(v1);
            continue;
        }

        int k = v.back().size();
        for (int i = 0; i < k; i++) {
            v.back().push_back(v[0].back());
            ans.push_back({v[0].back(), v.back()[i]});
            v[0].pop_back();
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif
    if (0) {
        for (int n = 1; n <= 100; n++) {
            db(n);
            solve(n);
        }
        auto v = solve((1 << 13) - 1);
        cout << v.size() << endl;
        exit(0);
    }

    int n;
    while (cin >> n) {
        auto res = solve(n);
        printf("%d\n", (int)res.size());
        for (auto o : res) printf("%d %d\n", o.first, o.second);
    }

    return 0;
}