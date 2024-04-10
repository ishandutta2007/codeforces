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

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        static char buf[(int)1.01e6];
        scanf("%d%d %s", &n, &k, buf);
        string s = buf;


        vector<int> mask(k);
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '0') mask[i % k] |= 1;
            if (c == '1') mask[i % k] |= 2;
            if (c == '?') mask[i % k] |= 4;
        }

        bool ok = 1;
        int cnt0 = 0, cnt1 = 0;
        for  (int i = 0; i < k; i++) {
            ok &= (mask[i] & 3) != 3;
            if (mask[i] & 1) cnt0++;
            if (mask[i] & 2) cnt1++;
        }

        ok &= cnt0 <= k / 2 && cnt1 <= k / 2;
        string res = ok ? "YES" : "NO";
        printf("%s\n", res.c_str());
    }

    return 0;
}