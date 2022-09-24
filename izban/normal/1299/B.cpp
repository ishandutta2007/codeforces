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

    int n;
    while (scanf("%d", &n) == 1) {
        vector<pair<int, int>> a(n);
        for (int i =0 ; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);

        vector<pair<int, int>> b;
        for (int i = 0; i < n; i++) {
            pair<int, int> v;
            v.first = a[(i + 1) % n].first - a[i].first;
            v.second = a[(i + 1) % n].second - a[i].second;
            b.push_back(v);
        }
        sort(b.begin(), b.end());

        bool ok =1;
        for (auto o : b) {
            auto v = o;
            v.first *= -1;
            v.second *= -1;
            ok &= binary_search(b.begin(), b.end(), v);
        }
        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}