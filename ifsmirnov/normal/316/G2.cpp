#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 2010;
const int maxk = 10;
typedef long long i64;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define pb push_back 
const i64 base = 10099;
typedef vector<i64> vi;

int k, n, m[maxk];
char s[maxn], t[maxk][maxn];
i64 h[maxn], th[maxk][maxn];
i64 p[maxn];
int lp[maxk], rp[maxk];
i64 res = 0;
int cnt[maxk][maxn];

i64 geth(i64 h[], int l, int r)
{
  return h[r] - (l ? h[l-1] * p[r-l] : 0);
}

void inith(char s[], i64 h[], int n)
{
  forn(i, n) {
    h[i] = s[i] + (i ? h[i-1] * base : 0);
    p[i] = base * (i ? p[i-1] : 1);
  }
}

void scan()
{
  scanf("%s", s);
  n = strlen(s);
  inith(s, h, n);
  scanf("%d", &k);
  forn(i, k) {
    scanf("%s%d%d", t[i], &lp[i], &rp[i]);
    m[i] = strlen(t[i]);
    inith(t[i], th[i], m[i]);
  }
}

void solve()
{
  forn(len, n+1) if (len) {
    vi ss;
    forn(i, n-len+1) {
      ss.pb(geth(h, i, i+len-1));
      //cout << geth(h, i, i+len-1) << " ";
    }
    //cout << endl;
    sort(all(ss));
    ss.erase(unique(all(ss)), ss.end());

    forn(i, k) forn(j, ss.size()) cnt[i][j] = 0;
    forn(i, k) forn(j, m[i]-len+1) {
      i64 h = geth(th[i], j, j+len-1);
      vi::iterator it = lb(all(ss), h);
      if (it != ss.end() && h == *it)
        ++cnt[i][it-ss.begin()];
    }

    forn(i, ss.size()) {
      bool ok = true;
      forn(j, k)
        if (cnt[j][i] < lp[j] || cnt[j][i] > rp[j]) {
          ok = false;
          break;
        }
      res += ok;
    }
  }

  cout << res << endl;
}

int main()
{
  //freopen("input.txt", "r", stdin);

  scan();
  solve();
}