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

    int n;
    while (cin >> n) {
        vector<pair<int, int>> a(n);
        map<int, int> cnt;
        map<pair<int, int>, int> mp;

        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            cnt[a[i].first]++;
            if (a[i].first != a[i].second) {
                cnt[a[i].second]++;
            }
            if (a[i].first > a[i].second) swap(a[i].first, a[i].second);

            if (a[i].first != a[i].second)
            mp[a[i]]++;
        }

        ll ans = 0;
        for (auto o : cnt) {
            ans += 1LL * o.second * (o.second - 1) / 2;
        }
        for (auto o : mp) {
            ans -= 1LL * o.second * (o.second - 1) / 2;
        }
        cout << ans << endl;
    }

    return 0;
}