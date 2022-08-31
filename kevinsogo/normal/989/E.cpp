#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200;
const int S = 20;

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0): x(x), y(y) {}
    pt operator-(const pt o) const {
        return pt(x - o.x, y - o.y);
    }
    ll cross(const pt o) const {
        return x * o.y - y * o.x;
    }
};

bool is_collinear(pt a, pt b, pt c) {
    return (a - b).cross(b - c) == 0;
}

inline void muli(int n, int i, double c[N][N], double a[N][N], double b[N][N]) {
    for (int j = 0; j < n; j++) {
        c[i][j] = 0;
        for (int k = 0; k < n; k++) {
            c[i][j] += a[i][k] * b[k][j];
        }
    }
}

inline void mul(int n, double c[N][N], double a[N][N], double b[N][N]) {
    for (int i = 0; i < n; i++) muli(n, i, c, a, b);
}

double mat[N][N], tem[N][N], mpows[S + 1][N][N];
void raise(int n, int i, int m) {
    for (int j = 0; j < n; j++) mat[i][j] = i == j;
    for (int s = 0; m; m >>= 1, s++) {
        if (m & 1) {
            muli(n, i, tem, mat, mpows[s]);
            for (int j = 0; j < n; j++) mat[i][j] = tem[i][j];
        }
    }
}

int parent[N*N];
int find(int i) {
    return parent[i] < 0 ? i : parent[i] = find(parent[i]);
}

void onion(int i, int j) {
    if ((i = find(i)) == (j = find(j))) return;
    if (parent[i] == parent[j]) parent[j]--;
    if (parent[i] < parent[j]) swap(i, j);
    parent[i] = j;
}

pt p[N];
vector<int> pts_of[N*N];
vector<int> lines_of[N];

int main() {
    int n;
    scanf("%d", &n);
    #define line(i, j) ((i) * n + (j))
    for (int i = 0; i < n * n; i++) parent[i] = -1;
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &p[i].x, &p[i].y);
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                if (is_collinear(p[i], p[j], p[k])) {
                    onion(line(i, j), line(i, k));
                    onion(line(i, j), line(j, k));
                }
            }
        }
    }
    vector<int> lines;
    lines.reserve(n * (n - 1) / 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int l = line(i, j);
            if (parent[l] < 0) {
                lines.push_back(l);
                for (int k = 0; k < n; k++) {
                    if (is_collinear(p[i], p[j], p[k])) {
                        pts_of[l].push_back(k);
                        lines_of[k].push_back(l);
                    }
                }
            }
        }
    }

    for (int s = 0; s < n; s++) {
        for (int l : lines_of[s]) {
            double prob = 1.0 / (pts_of[l].size() * lines_of[s].size());
            for (int k : pts_of[l]) mat[k][s] += prob;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mpows[0][i][j] = mat[i][j];
        }
    }
    for (int s = 0; s < S; s++) {
        mul(n, mpows[s + 1], mpows[s], mpows[s]);
    }

    int q;
    scanf("%d", &q);
    for (int t, m; q--;) {
        scanf("%d%d", &t, &m);
        double best = 0;
        raise(n, --t, --m);
        for (int l : lines) {
            double curr = 0;
            for (int k : pts_of[l]) curr += mat[t][k];
            best = max(best, curr / pts_of[l].size());
        }
        printf("%.11lf\n", best);
    }
}