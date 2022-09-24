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
#undef LOCAL


int getN() {
#ifdef LOCAL
#else
    int n;
    cin >> n;
    return n;
#endif
}

ll ask(int t, int i, int j, int k) {
    if (i == j || i == k || j == k) return 0;
#ifdef LOCAL
#else
    cout << t << " " << i << " " << j << " " << k << endl;
    ll x;
    cin >> x;
    return x;
#endif
}

ll ans(vector<int> p) {
#ifdef LOCAL
#else
    cout << 0;
    for (int i = 0; i < (int)p.size(); i++) cout << " " << p[i];
    cout << endl;
#endif
}


void solve() {
    int n = getN();

    int mn = 2;
    for (int i = 3; i <= n; i++) {
        ll s = ask(2, 1, mn, i);
        if (s < 0) {
            mn = i;
        }
    }

    vector<pair<ll, int>> vct;
    for (int i = 2; i <= n; i++) {
        vct.push_back({ask(1, 1, mn, i), i});
    }
    int furthest = max_element(vct.begin(), vct.end())->second;

    vector<pair<ll, int>> v1, v2;
    for (auto o : vct) {
        if (ask(2, 1, o.second, furthest) >= 0) {
            v1.push_back(o);
        } else {
            v2.push_back(o);
        }
    }
    sort(v1.begin(), v1.end());
    sort(v2.rbegin(), v2.rend());

    vector<int> perm;
    perm.push_back(1);
    for (auto o : v1) perm.push_back(o.second);
    for (auto o : v2) perm.push_back(o.second);

    ans(perm);
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  solve();

  return 0;
}