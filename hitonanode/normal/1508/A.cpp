#include <bits/stdc++.h>
using namespace std;
struct fast_ios { fast_ios(){ cin.tie(nullptr), ios::sync_with_stdio(false), cout << fixed << setprecision(20); }; } fast_ios_;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define REP(i, n) FOR(i,0,n)
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'; return os; }
#ifdef HITONANODE_LOCAL
const string COLOR_RESET = "\033[0m", BRIGHT_GREEN = "\033[1;32m", BRIGHT_RED = "\033[1;31m", BRIGHT_CYAN = "\033[1;36m", NORMAL_CROSSED = "\033[0;9;37m", RED_BACKGROUND = "\033[1;41m", NORMAL_FAINT = "\033[0;2m";
#define dbg(x) cerr << BRIGHT_CYAN << #x << COLOR_RESET << " = " << (x) << NORMAL_FAINT << " (L" << __LINE__ << ") " << __FILE__ << COLOR_RESET << endl
#else
#define dbg(x) (x)
#endif
 
string solve() {
    int N;
    cin >> N;
    vector<vector<pair<int, string>>> v(2);
    REP(_, 3) {
        string s;
        cin >> s;
        int n0 = count(s.begin(), s.end(), '0');
        int n1 = count(s.begin(), s.end(), '1');
        if (n0 > n1) v[0].emplace_back(n0, s);
        else v[1].emplace_back(n1, s);
    }
    REP(d, 2) if (v[d].size() >= 2) {
        sort(v[d].rbegin(), v[d].rend());
        string S = v[d][0].second;
        string T = v[d][1].second;
        int i = 0, j = 0;
        const char tgt = '0' + d;
        vector<int> cum;
        {
            int t = 0;
            for (auto c : T) {
                if (c == tgt) {
                    cum.push_back(t);
                    t = 0;
                } else {
                    t++;
                }
            }
            if (t) cum.push_back(t);
        }
        dbg(tgt);
        dbg(S);
        dbg(T);
        dbg(cum);

        int h = 0;
        string ret;
        for (auto c : S) {
            if (c == tgt) {
                if (h < cum.size()) ret += string(cum[h++], tgt ^ '0' ^ '1');
            }
            ret += c;
        }
        if (h < cum.size()) ret += string(cum[h++], tgt ^ '0' ^ '1');
        ret.resize(N * 3, '0');
        return ret;
    }
    exit(9);
}

int main() {
    int T;
    cin >> T;
    while (T--) cout << solve() << '\n';
}