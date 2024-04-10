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

    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        vector<string> a(n), b(n);
        for (int i = 0; i < n; i++) {
            static char buf[(int) 1.01e6];
            scanf("%s", buf);
            a[i] = buf;
        }
        for (int i = 0; i < n; i++) {
            static char buf[(int) 1.01e6];
            scanf("%s", buf);
            b[i] = buf;
        }

        const vector<int> dx = {1, -1, 0, 0};
        const vector<int> dy = {0, 0, 1, -1};
        const string ds = "DURL";

        vector<vector<int>> c(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                while (ds[c[i][j]] != b[i][j]) c[i][j]++;
            }
        }


        vector<vector<int>> vis(n, vector<int>(m));
        vector<vector<int>> cycle(n, vector<int>(m));
        vector<vector<int>> rem(n, vector<int>(m));
        vector<int> cycle_len;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (vis[x][y]) continue;

                int cx = x, cy = y;
                while (!vis[cx][cy]) {
                    vis[cx][cy] = 1;
                    int k = c[cx][cy];
                    cx += dx[k];
                    cy += dy[k];
                }

                if (vis[cx][cy] == 1) {
                    int clen = 0;
                    int cycle_id = cycle_len.size();
                    while (vis[cx][cy] == 1) {
                        cycle[cx][cy] = cycle_id;
                        vis[cx][cy] = 2;
                        rem[cx][cy] = clen;

                        clen++;
                        int k = c[cx][cy];
                        cx += dx[k];
                        cy += dy[k];
                    }
                    cycle_len.push_back(clen);
                }

                vector<pair<int, int>> vct;
                cx = x;
                cy = y;
                while (vis[cx][cy] == 1) {
                    vct.push_back({cx, cy});
                    int k = c[cx][cy];
                    cx += dx[k];
                    cy += dy[k];
                }

                reverse(vct.begin(), vct.end());
                for (auto o : vct) {
                    vis[o.first][o.second] = 2;
                    int k = c[o.first][o.second];
                    int nx = o.first + dx[k];
                    int ny = o.second + dy[k];
                    cycle[o.first][o.second] = cycle[nx][ny];
                    rem[o.first][o.second] = (rem[nx][ny] - 1 + cycle_len[cycle[o.first][o.second]]) %
                                             cycle_len[cycle[o.first][o.second]];
                }
            }
        }

        vector<vector<vector<vector<pair<int, int>>>>> cand(cycle_len.size());
        for (int i = 0; i < (int) cycle_len.size(); i++) {
            cand[i].assign(cycle_len[i], vector<vector<pair<int, int>>>(2));
        }

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                cand[cycle[x][y]][rem[x][y]][a[x][y] - '0'].push_back({x, y});
            }
        }

        vector<pair<int, int>> ans;
        int all = 0;
        int black = 0;
        for (int i = 0; i < (int) cycle_len.size(); i++) {
            for (int j = 0; j < (int)cand[i].size(); j++) {
                if (!cand[i][j][0].empty()) {
                    all++;
                    black++;
                    ans.push_back(cand[i][j][0][0]);
                } else if (!cand[i][j][1].empty()) {
                    all++;
                    ans.push_back(cand[i][j][1][0]);
                }
            }
        }
        printf("%d %d\n", all, black);
    }

    return 0;
}