#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
using namespace std;
template <typename T> bool chmin(T &m, const T q) { if (m > q) {m = q; return true;} else return false; }
int floor_lg(long long x) { return x <= 0 ? -1 : 63 - __builtin_clzll(x); }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#else
#define dbg(x) (x)
#endif

struct Sieve {
    std::vector<int> min_factor;
    std::vector<int> primes;
    Sieve(int MAXN) : min_factor(MAXN + 1) {
        for (int d = 2; d <= MAXN; d++) {
            if (!min_factor[d]) {
                min_factor[d] = d;
                primes.emplace_back(d);
            }
            for (const auto &p : primes) {
                if (p > min_factor[d] or d * p > MAXN) break;
                min_factor[d * p] = p;
            }
        }
    }
    // Prime factorization for 1 <= x <= MAXN^2
    // Complexity: O(log x)           (x <= MAXN)
    //             O(MAXN / log MAXN) (MAXN < x <= MAXN^2)
    template <typename T> std::map<T, int> factorize(T x) {
        std::map<T, int> ret;
        for (const auto &p : primes) {
            if (x < T(min_factor.size())) break;
            while (!(x % p)) x /= p, ret[p]++;
        }
        if (x >= T(min_factor.size())) ret[x]++, x = 1;
        while (x > 1) ret[min_factor[x]]++, x /= min_factor[x];
        return ret;
    }
    // Enumerate divisors of 1 <= x <= MAXN^2
    // Be careful of highly composite numbers <https://oeis.org/A002182/list> <https://gist.github.com/dario2994/fb4713f252ca86c1254d#file-list-txt>:
    // (n, (# of div. of n)): 45360->100, 735134400(<1e9)->1344, 963761198400(<1e12)->6720
    template <typename T> std::vector<T> divisors(T x) {
        std::vector<T> ret{1};
        for (const auto p : factorize(x)) {
            int n = ret.size();
            for (int i = 0; i < n; i++) {
                for (T a = 1, d = 1; d <= p.second; d++) {
                    a *= p.first;
                    ret.push_back(ret[i] * a);
                }
            }
        }
        return ret; // NOT sorted
    }
    // Moebius function Table, (-1)^{# of different prime factors} for square-free x
    // return: [0=>0, 1=>1, 2=>-1, 3=>-1, 4=>0, 5=>-1, 6=>1, 7=>-1, 8=>0, ...] <https://oeis.org/A008683>
    std::vector<int> GenerateMoebiusFunctionTable() {
        std::vector<int> ret(min_factor.size());
        for (unsigned i = 1; i < min_factor.size(); i++) {
            if (i == 1)
                ret[i] = 1;
            else if ((i / min_factor[i]) % min_factor[i] == 0)
                ret[i] = 0;
            else
                ret[i] = -ret[i / min_factor[i]];
        }
        return ret;
    }
};
Sieve sieve{1 << 15};  // (can factorize n <= 10^9)


int asklimit;
int asked;
bool ask(int h, int w, int I1, int J1, int I2, int J2) {
    asked++;
    if (asked > asklimit) exit(8);
    cout << "? " << h << " " << w << " " << I1 + 1 << " " << J1 + 1 << " " << I2 + 1 << " " << J2 + 1 << endl;
    int rrr;
    cin >> rrr;
    return rrr;
}

int answer(long long ret) {
    cout << "! " << ret << endl;
    exit(0);
}

int main() {
    int H, W;
    cin >> H >> W;
    asklimit = 3 * floor_lg(H + W);
    dbg(asklimit);

    const auto hfac = sieve.factorize(H);

    int hdiv = 1, wdiv = 1;
    for (auto [p, deg] : hfac) {
        int hlim = H;
        int tt = 0;
        while (deg--) {
            int unit = hlim / p;
            int up = unit;
            bool ok = true;
            if (tt == 0) {
                while (up < hlim and ok) {
                    if (up * 2 <= hlim) {
                        chmin(ok, ask(up, W, 0, 0, up, 0));
                        up *= 2;
                    } else {
                        chmin(ok, ask(hlim - up, W, 0, 0, up, 0));
                        up = hlim;
                    }
                }
            } else {
                int sz = unit * (p - 1);
                chmin(ok, ask(sz, W, 0, 0, sz, 0));
            }
            if (ok) hdiv *= p;
            else break;
            hlim /= p;
            tt++;
        }
    }

    const auto wfac = sieve.factorize(W);
    for (auto [p, deg] : wfac) {
        int wlim = W;
        int tt = 0;
        while (deg--) {
            int unit = wlim / p;
            int up = unit;
            bool ok = true;
            if (tt == 0) {
                while (up < wlim and ok) {
                    if (up * 2 <= wlim) {
                        chmin(ok, ask(H, up, 0, 0, 0, up));
                        up *= 2;
                    } else {
                        chmin(ok, ask(H, wlim - up, 0, 0, 0, up));
                        up = wlim;
                    }
                }
            } else {
                int sz = unit * (p - 1);
                chmin(ok, ask(H, sz, 0, 0, 0, sz));
            }
            if (ok) wdiv *= p;
            else break;
            wlim /= p;
            tt++;
        }
    }
    answer(1LL * sieve.divisors(hdiv).size() * sieve.divisors(wdiv).size());
}