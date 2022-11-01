    #include <cstdio>
    #include <vector>
    #include <cmath>
    #include <algorithm>
    using namespace std;

    typedef pair<int, int> pii;
    typedef pair<double, bool> pdb;

    inline double sqr(double p) {
        return p*p;
    }

    const double PI = acos(-1.0);
    const double EPS = 1e-8;

    void doAddInterval(vector<pdb> &intervals, double left, double right) {
        while (left > 0 && right >= 2*PI) {
            left -= 2*PI;
            right -= 2*PI;
        }
        while (left < 2*PI) {
            intervals.push_back(pdb(left + EPS, true));
            intervals.push_back(pdb(right - EPS, false));
            left += 2*PI;
            right += 2*PI;
        }
    }

    int main(void) {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<pii> pnts(n);
        vector<int> radii(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &pnts[i].first, &pnts[i].second, &radii[i]);
        }
        int bestInLine = min(2, n);
        for (int i = 0; i < n; i++) {
            vector<pdb> intervals;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                double ang = atan2((pnts[j].first - pnts[i].first)*1.0, (pnts[j].second - pnts[i].second) * 1.0);
                double dist = sqrt(sqr(pnts[j].first - pnts[i].first) + sqr(pnts[j].second - pnts[i].second));
                double d1 = asin((radii[i] + radii[j]) / dist);
                double d2 = asin((radii[i] - radii[j]) / dist);
                doAddInterval(intervals, ang - PI/2 + d2, ang - PI/2 + d1);
                doAddInterval(intervals, ang + PI/2 - d1, ang + PI/2 - d2);
            }
            sort(intervals.begin(), intervals.end());
            int balance = 1;
            for (size_t j = 0; j < intervals.size(); j++) {
                if (intervals[j].second) {
                    ++balance;
                    bestInLine = max(bestInLine, balance);
                } else
                    --balance;
            }
        }
        long long res = n;
        for (int i = 0; i < k; i++) {
            res += bestInLine + i;
        }
        printf("%I64d\n", res);
        return 0;
    }