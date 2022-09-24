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

int solve(vector<string> a) {
    int n = a.size();
    int m = a[0].size();

    int er = 0, ec = 0;
    for (int i = 0; i < n; i++) {
        char c = '.';
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            if (a[i][j] != c) {
                if (a[i][j] == '#') cnt++;
            }
            c = a[i][j];
        }
        if (cnt > 1) return -1;
        er += cnt == 0;
    }
    for (int j = 0; j < m; j++) {
        char c = '.';
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a[i][j] != c) {
                if (a[i][j] == '#') cnt++;
            }
            c = a[i][j];
        }
        if (cnt > 1) return -1;
        ec += cnt == 0;
    }
    if ((ec == 0) != (er == 0)) return -1;

    vector<int> dx{1, -1, 0, 0};
    vector<int> dy{0, 0, 1, -1};
    auto ok = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    };

    int ans = 0;
    for (int i= 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#') {
                ans++;
                vector<pair<int, int>> q;
                q.push_back({i, j});
                for (int t = 0; t < (int)q.size(); t++) {
                    int x = q[t].first;
                    int y = q[t].second;
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (ok(nx, ny) && a[nx][ny] == '#') {
                            a[nx][ny] = '.';
                            q.push_back({nx, ny});
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        vector<string> a(n);
        for (int i = 0; i < n; i++) {
            static char buf[(int)1.01e4];
            scanf("%s", buf);
            a[i] = buf;
        }

        printf("%d\n", solve(a));
    }

    return 0;
}