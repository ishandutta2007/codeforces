#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <cmath>
#include <cassert>
#include <queue>
#include <bitset>
#include <map>
#include <set>
#include <unordered_map>

#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef long long int64;
typedef pair<int, int> ii;
typedef vector<int> vi;

int a[10];

bool big_r;

int64 C[50][50];

int64 hash(vi v) {
  int64 h = 0;
  for (int x : v) {
    h = h * 23LL + x;
  }
  return h;
}

int vr[20], vl[20];

int64 comb(int* v, int s) {
  int64 res = 1;
  for (int i = 0; i < 10; ++i) {
    int x = v[i];
    if (x == 0) continue;
    if (x < s) res *= C[s][x];
    s -= x;
  }
  return res;
}

int64 doit(int* vr) {
  int64 val = 0;
  bool ok = true;
  int v[10];
  memcpy(v, a, sizeof(v));

  int sum = 0;
  int64 base = -1;
  for (int j = 0; j < 18; ++j) {
    int s = 0;
    for (int t = 0; t < vr[j]; ++t) {
      s += v[t];
    }
    if (s > 0) {
      if (base == -1) {
        sum = 0;
        for (int i = 0; i < 10; ++i) sum += v[i];
        base = comb(v, sum);
      }
      val += base * s / sum;
    }
    if (v[vr[j]] == 0) {
      ok = false;
      break;
    }

    if (base != -1) {
      base *= v[vr[j]];
      base /= sum;
      --sum;
    }
    --v[vr[j]];
  }
  if (ok) ++val;
  return val;
}

int calc(int pos, int cnt) {
  if (cnt == 0) {
    int64 cl = doit(vl);
    int64 cr = doit(vr);
    if (big_r && a[0] == 17 && a[1] == 1) ++cr;
    if (cr > cl) return 1;
    return 0;
  }
  if (pos == 10) return 0;
  int res = 0;
  for (int i = cnt; i >= 0; --i) {
    a[pos] = i;
    res += calc(pos + 1, cnt - i);
  }
  return res;
}


int main() {
  C[0][0] = 1;
  for (int i = 1; i < 50; ++i) {
    C[i][0] = 1;
    for (int j = 1; j < 50; ++j)
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
  }

  int64 l, r;
  cin >> l >> r;

  big_r = false;
  int64 big = 1000000000LL * 1000000000LL;

  if (r == big) {
    --r;
    big_r = true;
  }

  {
    int64 x = l - 1;
    for (int i = 0; i < 18; ++i) {
      vl[17 - i] = x % 10;
      x /= 10;
    }
  }
  {
    int64 x = r;
    for (int i = 0; i < 18; ++i) {
      vr[17 - i] = x % 10;
      x /= 10;
    }
  }

  int res = calc(0, 18);
  cout << res << "\n";
  return 0;
}