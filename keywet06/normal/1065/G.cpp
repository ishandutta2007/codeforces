#include <bits/stdc++.h>

namespace {

using int64 = long long;

int64 gcd(int64 a, int64 b) { return b == 0 ? a : gcd(b, a % b); }

template <typename T, typename U>
bool enlarge(T& a, U b) {
    return a < b ? (a = b, true) : false;
}

template <typename T, typename U>
bool minify(T& a, U b) {
    return a > b ? (a = b, true) : false;
}

const int64 inf = 2e18;

struct Solver {
    std::vector<std::string> fib{"0", "1"};

    int64 count(const std::string& s, const std::string& t) {
        int64 ret = 0;
        for (int i = 0; i + t.length() <= s.length(); ++i) {
            ret += s.substr(i, t.length()) == t;
        }
        return ret;
    }

    int64 count(int n, const std::string& t) {
        if (n < fib.size()) return count(fib[n], t);

        int tot = fib.size();
        assert(tot >= 4);
        int64 a = count(fib[tot - 4], t);
        int64 b = count(fib[tot - 3], t);
        int64 c = count(fib[tot - 2], t);
        int64 d = count(fib[tot - 1], t);

        std::vector<int64> cross_cnt{d - c - b, c - b - a};

        int64 x = c, y = d;
        for (int i = fib.size(); i <= n; ++i) {
            std::swap(x, y);
            std::swap(cross_cnt[0], cross_cnt[1]);
            y = std::min(inf, y + x + cross_cnt[0]);
        }
        return y;
    }

    void solve(int ca, std::istream& reader) {
        int n, m;
        int64 k;
        reader >> n >> k >> m;
        while (fib.size() < 4 || fib[fib.size() - 4].length() < m) {
            assert(fib.size() >= 2);
            fib.emplace_back(fib[(int)fib.size() - 2] + fib.back());
        }
        std::string result;
        for (int i = 0; i < m; ++i) {
            int64 tmp = count(n, result + "0");
            if (tmp >= k) {
                result.push_back('0');
            } else {
                result.push_back('1');
                k -= tmp;
            }
            if (fib.back().substr(fib.back().length() - result.length(), result.length()) == result) {
                --k;
            }
            if (k == 0) break;
        }
        puts(result.c_str());
    }
};

}  // namespace

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::istream& reader = std::cin;
    auto solver = std::make_unique<Solver>();
    solver->solve(1, reader);
    return 0;
}