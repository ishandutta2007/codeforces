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
typedef long double dbl;
const int Z = 26;

string srt(string s) {
    sort(s.begin(), s.end());
    return s;
}

string solve(string s) {
    int n = s.length();

    sort(s.begin(), s.end());
    if (s[0] == s.back()) {
        return s;
    }

    vector<int> cnt(Z);
    for (char c : s) {
        cnt[c - 'a']++;
    }
    
    for (int i = 0; i < Z; i++) {
        if (cnt[i] == 1) {
            string res = "";
            res += (char)('a' + i);
            cnt[i]--;
            for (int j = 0; j < Z; j++) {
                while (cnt[j]) {
                    res += (char)('a' + j);
                    cnt[j]--;
                }
            }
            return res;
        }
    }
    
    string res = "";

    int c0 = 0;
    while (c0 < Z && cnt[c0] == 0) c0++;
    assert(c0 < Z);

    int c1 = c0 + 1;
    while (c1 < Z && cnt[c1] == 0) c1++;
    assert(c1 < Z);

    int c2 = c1 + 1;
    while (c2 < Z && cnt[c2] == 0) c2++;
    assert(c2 <= Z);

    if (cnt[c0] - 2 > n - cnt[c0]) {
        res += (char)('a' + c0);
        cnt[c0]--;
        res += (char)('a' + c1);
        cnt[c1]--;

        if (c2 == Z) {
            while (cnt[c1]) {
                res += (char)('a' + c1);
                cnt[c1]--;
            }
            while (cnt[c0]) {
                res += (char)('a' + c0);
                cnt[c0]--;
            }
        } else {
            while (cnt[c0]) {
                res += (char)('a' + c0);
                cnt[c0]--;
            }
            res += (char)('a' + c2);
            cnt[c2]--;
            for (int i = 0; i < Z; i++) {
                while (cnt[i]) {
                    res += (char)('a' + i);
                    cnt[i]--;
                }
            }
        }
    } else {
        res += (char)('a' + c0);
        res += (char)('a' + c0);
        cnt[c0] -= 2;
        for (int i = c0 + 1; i < Z; i++) {
            while (cnt[i]) {
                res += (char)('a' + i);
                cnt[i]--;
                if (cnt[c0]) {
                    cnt[c0]--;
                    res += (char)('a' + c0);
                }
            }
        }
    }

    return res;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        static char buf[(int)2.01e6];
        scanf("%s", buf);
        string s = buf;

        auto res = solve(s);
        assert(srt(res) == srt(s));
        printf("%s\n", res.c_str());
    }

    return 0;
}