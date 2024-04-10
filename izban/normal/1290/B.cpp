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

bool check(string s, string a) {
    int n = s.length();
    vector<int> c1(26), c2(26);
    bool ok = 1;
    for (int i = 0; i < n - 1; i++) {
        c1[a[i] - 'a']++;
        c2[s[i] - 'a']++;
        ok &= c1 != c2;
    }
    return ok;
}

bool f1(string s) {
    int n = s.length();
    auto a = s;
    sort(a.begin(), a.end());
    do {
        if (check(a, s)) {
//            db(a);
            return 1;
        }
    } while (next_permutation(a.begin(), a.end()));
    return false;
}

bool f2(string s) {
    int n = s.length();
    if (n == 1) return 1;
    if (s[0] != s[n - 1]) return 1;

    for (int i = 1; i < n - 1; i++) {
        for (int j= i + 1; j < n - 1; j++) {
            if (s[i] != s[j] && s[0] != s[i] && s[0] != s[j]) {
                return 1;
            }
        }
    }
    return 0;

    string t1 = "", t2 = "";
    for (char c : s) {
        if (c == s[0]) t1 += c;
        else t2  += c;
    }
    if (t2.empty()) return 0;

    auto a1 = t2.substr(0, 1) + t1 + t2.substr(1);
    auto a2 = t2.substr(0, t2.size() - 1) + t1 + t2.substr(t2.size() - 1);
    db2(a1, a2);
    return check(s, a1) || check(s, a2);
}

void stress() {
    for (int it = 0;; it++) {
        mt19937 rnd(it);
        db(it);

        int n = rnd() % 10 + 1;
        string s = "";
        int c = rnd() % 5 + 1;
        for (int i = 0; i < n; i++) s += (char)('a' + rnd() % c);

        auto ans1 = f1(s);
        auto ans2 = f2(s);
//        db(s);
//        db2(ans1, ans2);
        assert(ans1 == ans2);
    }
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

//    stress();

    static char buf[(int)1.01e6];
    bool first = 1;
    while (scanf("%s", buf) == 1) {
        if (first) first = 0;
        else printf("\n");
        string s = buf;
        int n = s.length();

        vector<vector<int>> cnt(n + 1, vector<int>(26));
        for (int i = 1; i <= n; i++) {
            cnt[i] = cnt[i - 1];
            cnt[i][s[i - 1] - 'a'] ++;
        }

        int q;
        scanf("%d", &q);
        while (q--) {
            int l, r;
            scanf("%d%d", &l, &r);
            l--; r--;
//            db2(l, r);

            bool can = 0;
            if (l == r) can = 1;
            else if (s[l] != s[r]) {
                can = 1;
            } else  {
                int c =0;
                for  (int i= 0; i < 26; i++) {
                    c += cnt[r + 1][i] != cnt[l][i];
                }
                can = c >= 3;
            }
            string ans = can ? "Yes" : "No";
            printf("%s\n", ans.c_str());
        }
    }

    return 0;
}