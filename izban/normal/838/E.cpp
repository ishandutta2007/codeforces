#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = (int)1e9;

struct pt {
    int x, y;

    pt() {}
    pt(int _x, int _y) : x(_x), y(_y) {}

    pt operator- (const pt &p) const {
        return pt(x - p.x, y - p.y);
    }

    ll operator% (const pt &p) const {
        return 1LL * x * p.x + 1LL * y * p.y;
    }

    ll d2() const {
        return (*this) % (*this);
    }

    double d() const {
        return sqrt((double)d2());
    }
};

void upd(double &x, double y) {
    x = max(x, y);
}

const int N = 5050;
double dp[N / 2][N][2];

int main() {
#ifdef HOME
    freopen("in", "r", stdin);
#endif
    //cerr << sizeof(dp) << endl;

    int n;
    while (scanf("%d", &n) == 1) {
        vector<pt> a(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &a[i].x, &a[i].y);
        }
       
        for (int i = 0; i < n; i++) a.push_back(a[i]);

        int N = a.size();

        for (int i = 0; i < N / 2; i++) for (int j = 0; j < N; j++) for (int k = 0; k < 2; k++) dp[i][j][k] = -1;

        double ans = 0;
        function<double(int, int, int)> get = [&](int i, int j, int k) {
            if (i >= n) {
                i -= n;
                j -= n;
            }
            if (dp[i][j][k] > -0.5) return dp[i][j][k];
            dp[i][j][k] = 0;

            pt s = k == 0 ? a[i] : a[j];
            if (i + 1 != j) {
                upd(dp[i][j][k], get(i + 1, j, 0) + (a[i + 1] - s).d());
                upd(dp[i][j][k], get(i, j - 1, 1) + (a[j - 1] - s).d());
            }
            return dp[i][j][k];
        };

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n && i + j < N; j++) {
                for (int k = 0; k < 2; k++) {
                    ans = max(ans, get(i, i + j, k) + (a[i] - a[i + j]).d());
                }
            }
        }
        printf("%.15f\n", ans);

    }

#ifdef HOME
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
    return 0;
}