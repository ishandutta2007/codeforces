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

const int INF = 1e9;

ll solve(vector<int> a) {
    int n = a.size();
    ll sum = 0;
    for (int x : a) sum += x;

//    vector<ll> divs;
//    for (int i = 1; 1LL * i * i <= sum; i++) {
//        if (sum % i == 0) {
//            divs.push_back(i);
//            if (1LL * i * i != sum) divs.push_back(n / i);
//        }
//    }
//    sort(divs.begin(), divs.end());
//
    vector<ll> pr;
    ll x = sum;
    for (ll y = 2; y * y <= x; y++) {
        if (x % y == 0) {
            pr.push_back(y);
            while (x % y == 0) x/=y;
        }
    }
    if (x > 1) pr.push_back(x);

    if (pr.empty()) return -1;
//    db(sum);
//    dbv(pr);

    auto oa = a;
    ll ans = 1e18;
    for (ll k : pr) {
        a = oa;
        ll cans = 0;

        ll csum = 0;
        vector<pair<ll, int>> vct;
        for (int i = 0; i < n; i++) {
            if (csum > 0 && csum + a[i] >= k) {
                vct.push_back({k - csum, i});
                int j = 0;
                ll csum2 = 0;
                while (1) {
                    csum2 += vct[j].first;
                    if (csum2 * 2 >= k) break;
                    else j++;
                }
                for (auto o :vct) {
                    cans += 1LL * abs(vct[j].second - o.second) * o.first;
                }
                vct.clear();
                a[i] = (csum + a[i]) % k;
                csum = 0;
            } else a[i] %= k;

            if (a[i] > 0) {
                csum += a[i];
                vct.push_back({a[i], i});
            }
        }
//        db(k);
//        dbv(a);
//        for (auto o : vct){
//            db2(o.first, o.second);
//        }
//        db(csum);
        assert(vct.empty() && csum == 0);
        ans = min(ans, cans);
    }
//    db(ans);
    return ans;
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
      vector<int> a(n);
      for (int i = 0; i < n; i++) scanf("%d", &a[i]);

      printf("%lld\n", solve(a));
  }

  return 0;
}