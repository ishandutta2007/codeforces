#include <bits/stdc++.h>
#define mp(x, y) make_pair(x, y)
using namespace std;
typedef long long ll;
const int N = 2e5 + 5, mod1 = 998244353, mod2 = 1e9 + 7, bs = 2000;
const int b1 = 233333, b2 = 3339939;
void ast(ll x, ll l, ll r) { assert(x >= l && x <= r); }
int n, m;
string s[N];
ll f1[N], f2[N];
vector<ll> hs1[N], hs2[N];
vector<int> group[N];
int tot;
map<pair<ll, ll>, int> id;
int lcp[bs + 5][bs + 5], lcs[bs + 5][bs + 5];
vector<int> la[bs + 5];
void init(ll* f, vector<ll>* hs, ll b, ll mod, string s) {
  hs->push_back(0);
  for (int i = 1; i <= m; i++)
    hs->push_back((hs->back() * b % mod + s[i - 1]) % mod);
}
ll geths(ll* f, vector<ll>* hs, ll mod, int l, int r) {
  if (l > r) return -1;
  return (hs->at(r) - hs->at(l - 1) * f[r - l + 1] % mod + mod) % mod;
}
int num, rt, t[N * 2][26], Sum[N * 2];
int newnode() {
  num++;
  memset(t[num], 0, sizeof(t[num]));
  Sum[num] = 0;
  return num;
}
vector<vector<int> > ts[N];
bool cmp1(int x, int y) {
  int l = 0, r = m, ans;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (geths(f1, &hs1[x], mod1, 1, mid) == geths(f1, &hs1[y], mod1, 1, mid) &&
        geths(f2, &hs2[x], mod2, 1, mid) == geths(f2, &hs2[y], mod2, 1, mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  if (ans == m) return false;
  return s[x][ans] < s[y][ans];
}
bool cmp2(int x, int y) {
  int l = 1, r = m + 1, ans;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (geths(f1, &hs1[x], mod1, mid, m) == geths(f1, &hs1[y], mod1, mid, m) &&
        geths(f2, &hs2[x], mod2, mid, m) == geths(f2, &hs2[y], mod2, mid, m))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  if (ans == 1) return false;
  return s[x][ans - 2] < s[y][ans - 2];
}
int main() {
  f1[0] = f2[0] = 1;
  for (int i = 1; i < N; i++) {
    f1[i] = f1[i - 1] * b1 % mod1;
    f2[i] = f2[i - 1] * b2 % mod2;
  }
  // n = 4;
  // s[1] = "zzz";
  // s[2] = "bac";
  // s[3] = "abc";
  // s[4] = "acb";
  // n = 6;
  // s[1] = "acb";
  // s[2] = "abc";
  // s[3] = "cba";
  // s[4] = "bac";
  // s[5] = "cab";
  // s[6] = "bca";
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  m = s[1].size();
  for (int i = 1; i <= n; i++) {
    init(f1, &hs1[i], b1, mod1, s[i]);
    init(f2, &hs2[i], b2, mod2, s[i]);
  }
  for (int i = 1; i <= n; i++) {
    int vis[26];
    memset(vis, 0, sizeof(vis));
    for (int j = 0; j < int(s[i].size()); j++) vis[s[i][j] - 'a']++;
    ll hs1 = 0, hs2 = 0;
    for (int j = 0; j < 26; j++) {
      hs1 = (hs1 * b1 % mod1 + vis[j] + 1) % mod1;
      hs2 = (hs2 * b2 % mod2 + vis[j] + 1) % mod2;
    }
    if (!id[mp(hs1, hs2)]) id[mp(hs1, hs2)] = ++tot;
    group[id[mp(hs1, hs2)]].push_back(i);
  }
  ll sum = 1ll * n * (n - 1) / 2;
  ll ans = 0;
  if (n > bs) {
    vector<int> v;
    for (int i = 0; i <= m + 1; i++) v.push_back(0);
    for (int i = 1; i <= n; i++)
      for (int j = 0; j <= m; j++) ts[i].push_back(v);
  }
  for (int i = 1; i <= tot; i++) {
    int len = group[i].size();
    sum -= 1ll * len * (len - 1) / 2;
    if (n <= bs) {
      sort(group[i].begin(), group[i].end(), cmp1);
      for (int j = 0; j < len; j++) {
        int x = group[i][j];
        la[x].push_back(0);
        la[x].push_back(1);
        for (int k = 2; k <= m; k++)
          la[x].push_back((s[x][k - 1] >= s[x][k - 2]) ? la[x].back() + 1 : 1);
      }
      for (int j = 0; j < len; j++) {
        int las = m;
        for (int k = j + 1; k < len; k++) {
          int x = group[i][j], y = group[i][k];
          while (las &&
                 !(geths(f1, &hs1[x], mod1, 1, las) ==
                   geths(f1, &hs1[y], mod1, 1, las)) &&
                 !(geths(f2, &hs2[x], mod2, 1, las) ==
                   geths(f2, &hs2[y], mod2, 1, las)))
            las--;
          lcp[x][y] = lcp[y][x] = las;
        }
      }
      sort(group[i].begin(), group[i].end(), cmp2);
      for (int j = 0; j < len; j++) {
        int las = m;
        for (int k = j + 1; k < len; k++) {
          int x = group[i][j], y = group[i][k];
          while (las &&
                 !(geths(f1, &hs1[x], mod1, m - las + 1, m) ==
                   geths(f1, &hs1[y], mod1, m - las + 1, m)) &&
                 !(geths(f2, &hs2[x], mod2, m - las + 1, m) ==
                   geths(f2, &hs2[y], mod2, m - las + 1, m)))
            las--;
          lcs[x][y] = lcs[y][x] = las;
          if (lcp[x][y] != m) {
            int l = lcp[x][y] + 1, r = m - lcs[x][y];
            if (la[x][r] >= r - l + 1 || la[y][r] >= r - l + 1)
              ans++;
            else
              ans += 2;
          }
        }
      }
    } else {
      ll a = 0, b = 0, c = 0;
      for (int l = 0; l <= m; l++) {
        num = 0;
        rt = newnode();
        for (int j = 0; j < len; j++) {
          int x = group[i][j];
          int now = rt;
          for (int k = 1; k <= l; k++) {
            if (!t[now][s[x][k - 1] - 'a'])
              t[now][s[x][k - 1] - 'a'] = newnode();
            now = t[now][s[x][k - 1] - 'a'];
          }
          Sum[now]++;
          for (int r = m; r >= l + 2; r--) {
            if (!t[now][s[x][r - 1] - 'a'])
              t[now][s[x][r - 1] - 'a'] = newnode();
            now = t[now][s[x][r - 1] - 'a'];
            Sum[now]++;
          }
        }
        for (int j = 0; j < len; j++) {
          int x = group[i][j];
          int now = rt;
          for (int k = 1; k <= l; k++) {
            if (!t[now][s[x][k - 1] - 'a'])
              t[now][s[x][k - 1] - 'a'] = newnode();
            now = t[now][s[x][k - 1] - 'a'];
          }
          ts[x][l][m + 1] = max(0, Sum[now] - 1);
          for (int r = m; r >= l + 2; r--) {
            if (!t[now][s[x][r - 1] - 'a'])
              t[now][s[x][r - 1] - 'a'] = newnode();
            now = t[now][s[x][r - 1] - 'a'];
            ts[x][l][r] = max(0, Sum[now] - 1);
          }
        }
      }
      for (int j = 0; j < len; j++) {
        int x = group[i][j];
        int las = 1;
        for (int k = 2; k <= m; k++)
          if (s[x][k - 1] < s[x][k - 2]) {
            int l = las - 1, r = k;
            las = k;
            int s = ts[x][l][r];
            b += s;
          }
        int l = las - 1, r = m + 1;
        int s = ts[x][l][r];
        b += s;
      }
      c = 1ll * len * (len - 1) / 2 - b;
      ans += b + c * 2;
    }
  }
  sum *= 1337;
  // printf("%lld %lld\n", sum, ans);
  printf("%lld\n", ans + sum);
}
/*
s[1] = "acb";
s[2] = "abc";
s[3] = "cba";
s[4] = "bac";
s[5] = "cab";
s[6] = "bca";
*/