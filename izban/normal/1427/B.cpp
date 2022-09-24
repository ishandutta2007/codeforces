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

int solve(int n, int k, string s) {
    vector<pair<int, int>> vct;

    const int INF = 1e9;
    s = "L" + s + "L";
    for (int i = 1; i <= n;) {
        if (s[i] == 'W') {
            i++;
            continue;
        }
        int j = i;
        while (j <= n && s[j] == s[i]) j++;

        int cost = 0;
        if (s[i - 1] == 'W' && s[j] == 'W') {
            cost = j - i;
        } else {
            if (s[i - 1] == 'W' || s[j] == 'W') {
                cost = INF;
            } else {
                cost = INF;
            }
        }
        if (cost != INF || i != 1) {
            for (int k = i; k < j; k++) {
                vct.push_back({cost, k});
            }
        } else {
            for (int k = j - 1; k >= i; k--) {
                vct.push_back({cost, k});
            }
        }

        i = j;
    }
    stable_sort(vct.begin(), vct.end(), [&](pair<int, int> x, pair<int, int> y) {
        return x.first < y.first;
    });

    for (int i = 0; i < min((int)vct.size(), k); i++) {
        s[vct[i].second] = 'W';
    }

    int ans =0 ;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'W') {
            ans++;
            if (s[i - 1] == 'W') {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    while (T--) {
        int n, k;
        scanf("%d%d", &n, &k);
        static char buf[(int)1.01e6];
        scanf("%s", buf);
        string s= buf;

        printf("%d\n", solve(n, k, s));
    }

    return 0;
}