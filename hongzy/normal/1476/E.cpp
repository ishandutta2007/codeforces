#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;

const int N = 2e5 + 10;
const int mod = 1e9 + 7;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<long long> ran(0, 1ll << 62);
void ucin() {
  ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }

inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }
int n, m, k, ans[N], tim[N];
char p[N][8], s[N][8];
map<string, int> ID;
vector<int> mat[N], vec[N];
set<int> num;
bool use[N];
void BAD() {
  puts("NO"); exit(0);
}
vector<int> G[N];
int seq[N], deg[N], pos[N];
void topology() {
  queue<int> q;
  rep(i, 1, n) if(!deg[i]) q.push(i);
  while(q.size()) {
    int u = q.front(); q.pop();
    seq[++ seq[0]] = u; pos[u] = seq[0];
    rep(i, 0, (int) G[u].size() - 1) {
      int v = G[u][i];
      if(!-- deg[v]) {
        q.push(v);
      }
    }
  }
  if(seq[0] < n) BAD();
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  rep(i, 1, n) {
    scanf("%s", p[i]);
    ID[string(p[i])] = i;
  }
  rep(i, 1, m) {
    int z;
    scanf("%s%d", s[i], &z);
    char tmp[8];
    tmp[k] = 0;
    for(int st = 0; st < (1 << k); st ++) {
      copy(s[i], s[i] + k, tmp);
      for(int j = 0; j < k; j ++) if(st >> j & 1) tmp[j] = '_';
      int id = ID[string(tmp)];
      if(id && tim[id] < i) {
        tim[id] = i; mat[i].pb(id);
        // printf("s%d to p%d\n", i, id);
      }
    }
    bool Z = 0;
    for(int x : mat[i]) {
      if(x != z) G[z].pb(x), deg[x] ++;
      else Z = 1;
    }
    if(!Z) BAD();
    // vec[z].pb(i);
  }
  topology();
  puts("YES");
  rep(i, 1, n) printf("%d%c", seq[i], " \n"[i == n]);
  return 0;
}