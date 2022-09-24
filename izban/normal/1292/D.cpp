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

bool ispr(int x) {
    for (int i = 2; i * i <= x; i++) if (x % i == 0) return 0;
    return 1;
}

ll solve(vector<int> a) {
    int m = *max_element(a.begin(), a.end()) + 5;
    vector<int> cnt(m);
    for  (int x : a) cnt[x]++;

    vector<int> pr;
    for (int i = 2; i < m; i++) if (ispr(i)) pr.push_back(i);

    struct node {
        vector<pair<node*, int>> ch; // to, len
        int cnt{0};
        ll sumlen{0};
        int id{-1};
    };
    int cnode =0 ;
    vector<node> nodes(m * 4);
    for (int i = 0; i < (int)nodes.size(); i++) {
        nodes[i].id = i;
        nodes[i].cnt = 0;
        nodes[i].sumlen = 0;
    }
    auto new_node= [&]() {
        assert(cnode < (int)nodes.size());
        return &nodes[cnode++];
    };

    auto calc = [&](int l, int pr_id) {
        int x = l;
        int res = 0;
        while (x) {
            res += x / pr[pr_id];
            x /= pr[pr_id];
        }
        return res;
    };

    vector<node*> ptr(m);

    function<pair<node*, int>(int, int, int)> rec = [&](int l, int r, int pr_id) {
        assert(pr_id >= 0);
        if (l == r) {
            auto root = new_node();
            int len = 0;
            for (int j = 0; j <= pr_id; j++) {
                len += calc(l, j);
            }
            ptr[l] = root;
            return make_pair(root, len);
        }
        if (calc(l, pr_id) == calc(r, pr_id)) {
            auto res = rec(l, r, pr_id - 1);
            res.second += calc(l, pr_id);
            return res;
        }
        vector<pair<int, int>> vct;
        for (int L = l; L <= r;) {
            int R;
            R = (L / pr[pr_id] + 1) * pr[pr_id] - 1;
            R = min(R, r);

            vct.push_back({L, R});

            L = R + 1;
        }
        pair<node*, int> cur;
        cur.first = nullptr;
        for (int i = (int)vct.size() - 1; i >= 0; i--) {
            auto nw = rec(vct[i].first, vct[i].second, pr_id);
            if (cur.first != nullptr) {
                auto lca = new_node();
                int tmp = calc(vct[i].first, pr_id);
                cur.second -= tmp;
                nw.second -= tmp;
                assert(cur.second >= 0);
                assert(nw.second >= 0);
                lca->ch.push_back(cur);
                lca->ch.push_back(nw);
                nw = make_pair(lca, tmp);
            }
            cur = nw;
        }
        return cur;
    };

    auto root = new_node();
    for (int i = 0; i < (int)pr.size(); i++) {
        int to = i + 1 == (int)pr.size() ? m : pr[i + 1];
        auto cur = rec(pr[i], to - 1, i);
        root->ch.push_back(cur);
    }
    ptr[0] = ptr[1] = root;

    for (int i = 0; i < m; i++) {
        ptr[i]->cnt += cnt[i];
    }


    function<void(node*)> dfs = [&](node *v) {
        for (auto to : v->ch) {
            dfs(to.first);
            v->cnt += to.first->cnt;
            v->sumlen += to.second * 1LL * to.first->cnt + to.first->sumlen;
        }
    };
    dfs(root);

    int all_cnt = root->cnt;
    ll ans = root->sumlen;

    node *v = root;
    while (1) {
        bool found = 0;
        for (auto to : v->ch) {
            if (to.first->cnt * 2 > all_cnt) {
                found = 1;
                ans -= to.second * 1LL * to.first->cnt;
                ans += to.second * 1LL * (all_cnt - to.first->cnt);
                v = to.first;
                break;
            }
        }
        if (!found) break;
    }

    return ans;
}

void test() {
    vector<int> a;
    for (int i = 0; i < 1e6; i++) a.push_back(i % 5001);
    printf("%lld\n", solve(a));
    exit(0);
}

void test2() {
    vector<int> a;
    for (int i = 0; i < 1e6; i++) a.push_back(i % 2 == 0 ? 5000 : 4777);
    printf("%lld\n", solve(a));
    exit(0);
}

ll slow(vector<int> a) {
    int m = *max_element(a.begin(), a.end()) + 3;

    vector<int> cnt(m);
    for (int x : a) cnt[x]++;

    vector<int> pr;
    for (int i = 2; i < m; i++) if (ispr(i)) pr.push_back(i);
    int k = pr.size();

    map<vector<int>, int> mp;

    auto get = [&](const vector<int> &v) {
        if (!mp.count(v)) {
            int sz =mp.size();
            mp[v] =sz;
        }
        return mp[v];
    };
    get(vector<int>(k, 0));

    vector<pair<int, int>> ed;
    vector<int> c(1e5);

//    db("");
    for (int i = 2; i < m; i++) {
        vector<int> v(k);
        for (int j = 0; j < k; j++) {
            int x = i;
            while (x) {
                v[j] += x / pr[j];
                x /= pr[j];
            }
        }
//        dbv(v);

        c[get(v)] += cnt[i];
        while (1) {
            int j = 0;
            while (j < k && v[j] == 0) j++;
            if (j == k) break;
            int u = get(v);
            v[j]--;
            int to = get(v);
            ed.push_back({u, to});
        }
    }
    c[0] += cnt[0] + cnt[1];


    int z = mp.size();
    vector<vector<int>> e(z);
    for (auto o : ed) {
        e[o.first].push_back(o.second);
        e[o.second].push_back(o.first);
    }

    const int INF = 1e9;
    ll ans = INF;
    for (int s= 0; s < z; s++) {
        vector<int> d(z, INF);
        queue<int> q;
        q.push(s);
        d[s] = 0;
        while (!q.empty()) {
            int v= q.front();
            q.pop();
            for (int to : e[v]) {
                if (d[to] > d[v] + 1) {
                    d[to] = d[v] + 1;
                    q.push(to);
                }
            }
        }
        ll res = 0;
        for (int i = 0; i < z; i++) res += d[i] * c[i];
        ans = min(ans, res);
    }
    return ans;
}

void stress() {
    for (int it = 251;; it++ ){
        db(it);

        mt19937 rnd(it);
        const int N = 30;
        int n = rnd() % N + 1;
        int m = rnd() % N + 1;
        vector<int> a(n);
        for  (int i= 0 ; i < n; i++) a[i] = rnd() % m;

        auto ans1 = solve(a);
        auto ans2 = slow(a);
        if (ans1 != ans2) {
            db2(ans1, ans2);
            dbv(a);
            exit(0);
        }
    }
}

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
//  test();
//  test2();
//    stress();

  int n;
  while (scanf("%d", &n) == 1) {
      vector<int> a(n);
      for (int i = 0; i < n; i++) scanf("%d", &a[i]);

      printf("%lld\n", solve(a));
//      if (n == 5) break;
  }

  return 0;
}