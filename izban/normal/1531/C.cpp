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


int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    while (cin >> n) {
        int k = 1;
        while (k * k < n) k++;

        if (n == 1) {
            cout << 1 << endl << "o" << endl;
            continue;
        }
        if (n == 2) {
            cout << -1 << endl;
            continue;
        }

        if (n == k * k - 2) k++;

        vector<string> a(k, string(k, '.'));
        for (int i = 0; i < k - 1; i++) {
            for (int j = 0; j < k - 1; j++) {
                a[k - 1 - i][j] = 'o';
            }
        }

        if (n == (k - 1) * (k - 1) - 2) {
            a[1][k - 2] = a[1][k - 3] = a[2][k - 2] = a[2][k - 3] = '.';
            a[0][0] = 'o';
            a[k - 1][k - 1] = 'o';
        } else {

            int need = n - (k - 1) * (k - 1);
            if (need % 2 == 1 && n != k * k) {
                a[1][k - 2] = '.';
                need++;
            }
            for (int i = 0; i < need; i++) {
                if (i % 2 == 0) {
                    a[k - 1 - i / 2][k - 1] = 'o';
                } else {
                    a[0][i / 2] = 'o';
                }
            }
        }

        cout << k << endl;
        for (auto s : a) cout << s << endl;
    }

    return 0;
}