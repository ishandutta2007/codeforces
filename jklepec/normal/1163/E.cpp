#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int MAXN = 5e5 + 5;

static const int MultiplyDeBruijnBitPosition[32] =
{
  0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
  31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
};
int lowest_bit(int v) {
  return MultiplyDeBruijnBitPosition[((uint32_t)((v & -v) * 0x077CB531U)) >> 27];
}

int a[MAXN];
int bio[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  REP(i, n) {
    cin >> a[i];
  }

  int best = 0;
  vector<int> base;

  for(int ii = 1; ii < 20; ii ++) {
    int i = (1 << ii);
    vector<int> v;
    REP(j, n) {
      if(a[j] < i) {
        v.pb(a[j]);
      }
    }

    bio[0] = i;
    vector<int> tmp_base;
    vector<int> ljuska = {0};

    for(auto x: v) {
      if(bio[x] == i) continue;
      tmp_base.pb(x);

      int N = ljuska.size(); REP(j, N) {
        int y = ljuska[j];
        bio[x^y] = i;
        ljuska.pb(x^y);
      }
    }

    if((int) ljuska.size() == i) {
      best = ii;
      base = tmp_base;
    }
  }

  int tmp = 0;
  cout << best << endl;
  cout << 0 << " ";
  for(int i = 1; i < (1 << best); ++i) {
    tmp ^= base[lowest_bit(i)];
    cout << tmp << " ";
  }
  cout << endl;
}