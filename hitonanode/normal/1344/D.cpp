#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
using namespace std;
using lint = long long;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)

// x^3 - ax, x \geq 0 (convex)
struct Cubic {
    int a, lb, ub;
    Cubic(int a, int ub) : a(a), lb(0), ub(ub) {}
    int slope(long long s) const noexcept {
        int lo = lb, hi = ub + 1;
        while (hi - lo > 1) {
            int x = (lo + hi) / 2;
            (next_cost(x) <= s ? lo : hi) = x;
        }
        return lo;
    }
    long long eval(long long x) const noexcept { return (x * x - a) * x; }
    long long next_cost(long long x) const noexcept { return 3 * x * x - 3 * x + 1 - a; }
};

template <typename F, typename Int, Int INF> struct ConvexSumMinimizationUnderLinearConstraint {
    std::pair<Int, std::vector<std::vector<std::pair<Int, Int>>>> solve(const std::vector<Int> &k, const std::vector<F> &f, Int C) {
        assert(k.size() == f.size());
        assert(k.size() > 0);
        Int lbsum = 0, ubsum = 0;
        for (auto func : f) lbsum += func.lb, ubsum += func.ub;
        if (lbsum > C or ubsum < C) return {};

        const int N = k.size();
        Int few = -INF, enough = INF; //  few  C  /  enough 
        Int fewc = 0;
        while (enough - few > 1) {
            auto slope = few + (enough - few) / 2;
            Int cnt = 0;
            for (int i = 0; i < N; i++) {
                auto tmp = f[i].slope(slope);
                cnt += tmp * k[i];
                if (cnt >= C) break;
            }
            if (cnt >= C) {
                enough = slope;
            } else {
                few = slope;
                fewc = cnt;
            }
        }

        std::vector<std::vector<std::pair<Int, Int>>> ret(N);
        std::vector<int> additional;
        Int ctmp = 0;
        Int sol = 0;
        for (int i = 0; i < N; i++) {
            auto xlo = f[i].slope(few);
            auto xhi = f[i].slope(few + 1);
            ctmp += k[i] * xlo;
            ret[i].emplace_back(xlo, k[i]);
            if (xlo < xhi) additional.push_back(i);
            sol += k[i] * f[i].eval(xlo);
        }
        sol += (C - ctmp) * (few + 1);
        while (additional.size()) {
            int i = additional.back();
            additional.pop_back();
            Int add = C - ctmp > k[i] ? k[i] : C - ctmp;
            auto x = ret[i][0].first;
            if (add) {
                ret[i][0].second -= add;
                if (ret[i][0].second == 0) ret[i].pop_back();
                ret[i].emplace_back(x + 1, add);
                ctmp += add;
            }
        }
        // Int ret2 = 0;
        // for (int i = 0; i < N; i++) {
        //     for (auto p : ret[i]) {
        //         Int x = p.first, n = p.second;
        //         Int y = f[i].eval(x);
        //         ret2 += y * n;
        //     }
        // }
        // assert(sol == ret2);
        return {sol, ret};
    }
};

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int N;
    lint K;
    cin >> N >> K;
    vector<lint> A(N);
    for (auto &a : A) cin >> a;

    vector<Cubic> functions;
    for (auto a : A) functions.emplace_back(a, a);
    ConvexSumMinimizationUnderLinearConstraint<Cubic, lint, (1LL << 62) - 1> solver;
    auto ret = solver.solve(vector<lint>(N, 1), functions, K);
    if (ret.second.empty()) return 0;
    for (auto p : ret.second) cout << lint(p[0].first) << ' ';
    cout << '\n';
}