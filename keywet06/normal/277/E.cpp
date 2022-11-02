#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 405;

int iq[N * 2];
int ra[N * 2];
int sce, dst;
vector<int> re[N * 2];
int rf[N * 2][N * 2];
int rc[N * 2][N * 2];
int n;

double co[N * 2][N * 2], rd[N * 2];

const double eps = 1e-6;
int cmp(double x, double y) {
    if (x + eps < y) return -1;
    if (y + eps < x) return 1;
    return 0;
}

bool BF() {
    for (int i = 0; i < 2 * N; ++i) rd[i] = 0;
    memset(ra, -1, sizeof(ra));
    memset(iq, 0, sizeof(iq));
    queue<int> Q;
    ra[sce] = sce, rd[sce] = 0, iq[sce] = 1, Q.push(sce);
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        if (x == dst) continue;
        iq[x] = 0;
        for (auto &y : re[x]) {
            if (rf[x][y] < rc[x][y] &&
                (ra[y] == -1 || cmp(rd[x] + co[x][y], rd[y]) == -1)) {
                rd[y] = rd[x] + co[x][y], ra[y] = x;
                if (!iq[y]) Q.push(y), iq[y] = 1;
            }
        }
    }
    if (ra[dst] == -1) return false;
    return true;
}

int main() {
    cin >> n;
    vector<int> rx(n), ry(n);
    for (int i = 0; i < n; ++i) cin >> rx[i] >> ry[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (ry[i] > ry[j]) {
                double dist = sqrt((rx[i] - rx[j]) * (rx[i] - rx[j]) +
                                   (ry[i] - ry[j]) * (ry[i] - ry[j]));
                re[i].push_back(n + j);
                re[n + j].push_back(i);
                rc[i][n + j] = 1;
                co[i][n + j] = dist;
                co[n + j][i] = -dist;
            }
    sce = 2 * n;
    dst = 2 * n + 1;
    for (int i = 0; i < n; ++i) {
        re[sce].push_back(i);
        re[i].push_back(sce);
        rc[sce][i] = 2;
        re[i + n].push_back(dst);
        re[dst].push_back(i);
        rc[i + n][dst] = 1;
    }
    int flow;
    double cost = 0;
    for (flow = 0; BF(); ++flow) {
        cost += rd[dst];
        for (int i = dst; i != sce; i = ra[i]) ++rf[ra[i]][i], --rf[i][ra[i]];
    }
    if (flow != n - 1) return cout << "-1\n", 0;
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(10);
    cout << cost << "\n";
    return 0;
}