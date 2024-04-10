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
typedef long double dbl;

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  string s;
  while (T--) {
      int r;
      cin >> r;

      enum type {
          LEAF, SERIES, PARALLEL
      };
      struct node {
          type t;
          vector<node*> e;
          dbl sum;
      };
      getline(cin, s);

      int cur = 0;
      auto skip_spaces = [&]() {
          while (cur < (int)s.length() && s[cur] == ' ') cur++;
      };
      auto get_symbol = [&]() {
          skip_spaces();
          assert(cur < (int)s.length());
          return s[cur++];
      };

      function<node*()> parse = [&]() {
          node* res = new node();

          char c = get_symbol();
          if (c == '*') {
              res->t = LEAF;
          } else {
              res->e.push_back(parse());
              res->t = LEAF;
              while (1) {
                  c = get_symbol();
                  if (c == ')') break;
                  assert(c == 'S' || c == 'P');
                  auto old = res->t;
                  if (c == 'S') res->t = SERIES;
                  else res->t = PARALLEL;
                  assert(old == LEAF || old == res->t);
                  res->e.push_back(parse());
              }
          }

          return res;
      };

      node* root = parse();

      function<void(node*)> dfs = [&](node *root) {
          if (root->t == LEAF) {
              root->sum = 1;
              return;
          }
          if (root->t == SERIES) {
              root->sum = 1e20;
              for (auto to : root->e) {
                  dfs(to);
                  root->sum = min(root->sum, to->sum);
              }
              return;
          }
          root->sum = 0;
          vector<dbl> v;
          for (auto to : root->e) {
              dfs(to);
              v.push_back(to->sum);
          }
          dbl sumsqrt = 0;
          for (int i = 0; i < (int)v.size(); i++) {
              root->sum += v[i];
              sumsqrt += sqrt(v[i]);
          }
          for (int i = 0; i < (int)v.size(); i++) {
              root->sum += sqrt(v[i]) * (sumsqrt - sqrt(v[i]));
          }
      };
      dfs(root);

      vector<ll> ans;
      function<void(node*, dbl)> dfs2 = [&](node *root, dbl r) {
//          db(r);
          if (root->t == LEAF) {
              ans.push_back(round(r));
              assert(fabs(r - round(r)) < 1e-3);
              return;
          }
          if (root->t == SERIES) {
              int j = 0;
              for (int i= 1; i < (int)root->e.size(); i++) if (root->e[i]->sum < root->e[j]->sum) j = i;
              for (int i = 0; i < (int)root->e.size(); i++) {
                  dfs2(root->e[i], i == j ? r : 0);
              }
              return;
          }
          dbl sumsqrt = 0;
          for (int i = 0; i < (int)root->e.size(); i++) {
              sumsqrt += sqrt(root->e[i]->sum);
          }
          for (int i = 0; i < (int)root->e.size(); i++) {
              dbl nr = r * ((sumsqrt - sqrt(root->e[i]->sum)) / sqrt(root->e[i]->sum) + 1);
              dfs2(root->e[i], nr);
          }
      };
      dfs2(root, r);
      cout << "REVOLTING";
      for (auto x : ans) cout << " " << x;
      cout << "\n";
  }

  return 0;
}