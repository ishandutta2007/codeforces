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

struct segtree {
    struct item {
        int new_blocked;
        string new_color[2];

        item() = default;
        item(string s) {
            new_blocked = -1;
            new_color[0] = new_color[1] = "";

            if (s == "lock") new_blocked = 1;
            else if (s == "unlock") new_blocked = 0;
            else new_color[0] = s;
        }

        item(item x, item y) {
            new_blocked = -1;
            new_color[0] = new_color[1] = "";

            new_blocked = y.new_blocked == -1 ? x.new_blocked : y.new_blocked;
            for (int i = 0; i < 2; i++) {
                int cur_blocked = i;
                string cur_color = "";
                cur_color = x.new_color[cur_blocked];
                cur_blocked = x.new_blocked == -1 ? cur_blocked : x.new_blocked;

                if (y.new_color[cur_blocked] != "") cur_color = y.new_color[cur_blocked];
                new_color[i] = cur_color;
            }
        }
    };

    int n;
    vector<string> a;
    vector<item> t;

    segtree(vector<string> _a) {
        a = _a;
        n = a.size();
        t.resize(4 * n);
        build(1, 0, n - 1);
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = item(a[tl]);
            return;
        }
        int tm = (tl + tr) >> 1;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = item(t[v * 2], t[v * 2 + 1]);
    }

    void upd(int v, int tl, int tr, int x, string s) {
        if (tl == tr) {
            a[tl] = s;
            t[v] = item(a[tl]);
            return;
        }
        int tm = (tl + tr) >> 1;
        if (x <= tm) upd(v * 2, tl, tm, x, s);
        else upd(v * 2 + 1, tm + 1, tr, x, s);
        t[v] = item(t[v * 2], t[v * 2 + 1]);
    }

    void print() {
        string res = t[1].new_color[0];
        if (res == "") {
            res = "blue";
        }
        printf("%s\n", res.c_str());
    }
};

int main() {
#ifdef LOCAL
    freopen("in", "r", stdin);
#endif

    int n;
    static char buf[1111];
    while (scanf("%d", &n) == 1) {
        vector<string> a(n);
        for (auto &s : a) {
            scanf("%s", buf);
            s = buf;
        }

        segtree t(a);
        int q;
        scanf("%d", &q);
        t.print();
        for (int i = 0; i < q; i++) {
            int id;
            scanf("%d%s", &id, buf);
            t.upd(1, 0, n - 1, id - 1, buf);
            t.print();
        }
    }

    return 0;
}