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

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    string s;
    while (cin >> s) {
        int n = s.length();
        vector<vector<int>> ans;
        while (1) {
            int i = 0;
            int j = n - 1;

            vector<int> cur;
            while (1) {
                while (i <= j && s[i] != '(') i++;
                while (j >= i && s[j] != ')') j--;

                if (i <= j) {
                    cur.push_back(i);
                    cur.push_back(j);
                    s[i] = s[j] = 'x';
                    i++;
                    j--;
                } else {
                    break;
                }
            }
            if (cur.empty()) {
                break;
            } else {
                ans.push_back(cur);
            }
        }
        cout << ans.size() << endl;
        for (auto v : ans) {
            sort(v.begin(), v.end());
            cout << v.size() << endl;
            for (int x : v) cout << x + 1 << " ";
            cout << endl;
        }
    }

    return 0;
}