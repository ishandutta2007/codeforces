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

string solve(string s) {
    int x = 0;
    while (x < (int)s.length() - 1 - x && s[x] == s[(int)s.length() - 1 - x]) x++;

    string t = s.substr(0, x);
    s = s.substr(x, (int)s.length() - 2 * x);

    int n = s.length();

    string ans;


    vector<int> d1(n), d2(n);
    int l=0, r=-1;
    int k;
    for(int i = 0; i < n; i++){
        if(i > r) k = 1;
        else k = min(d1[l + r - i], r - i);

        while(0 <= i-k && i+k < n && s[i - k] == s[i + k]) k++;
        d1[i] = k;
        if(i + k - 1 > r)
            r = i + k - 1, l = i - k + 1;
    }
    
    l=0, r=-1;
    for(int i = 0; i < n; i++){
        if(i > r) k = 0;
        else k = min(d2[l + r - i + 1], r - i + 1);

        while(i + k < n && i - k - 1 >= 0 && s[i+k] == s[i - k - 1]) k++;
        d2[i] = k;

        if(i + k - 1 > r)
            l = i - k, r = i + k - 1;
    }

    int L = 0, R = 0;
    auto upd = [&](int cL, int cR) {
        if (cR - cL > R - L) {
            L = cL;
            R = cR;
        }
    };

    for (int i = 0; i < n; i++) {
        int cL = i - d1[i] + 1;
        int cR = i + d1[i] - 1;
        if (cL == 0 || cR == n - 1) {
            upd(cL, cR);
        }
    }
    for (int i = 0; i < n; i++) {
        if (d2[i] == 0) continue;

        int cL = i - d2[i];
        int cR = i + d2[i] - 1;
        if (cL == 0 || cR == n - 1) {
            upd(cL, cR);
        }
    }

    ans = s.substr(L, R - L + 1);

    ans = t + ans;
    reverse(t.begin(), t.end());
    ans += t;

    return ans;
}

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int T;
    scanf("%d", &T);
    while (T--) {
        const int N = 1.01e6;
        static char buf[N];
        scanf("%s", buf);

        string s = buf;

        string res = solve(s);
        printf("%s\n", res.c_str());
    }

    return 0;
}