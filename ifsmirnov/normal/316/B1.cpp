#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1050;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int> vi;

int n;
int t[maxn], p[maxn];
int x;
int sx;
vi a;
int b[maxn];
int d[maxn][maxn*2];
int k;

void scan()
{
  cin >> n >> x; --x;
  forn(i, n) p[i] = -1;
  forn(i, n) { 
    cin >> t[i]; --t[i];
    if (t[i] != -1) {
      p[t[i]] = i;
    }
  }
}

void solve()
{
  forn(i, n) if (p[i] == -1) {
    bool our = (i == x);
    int cnt = 1;
    for (int j = i; t[j] != -1; j = t[j]) {
      if (j == x || t[j] == x) our = true;
      ++cnt;
    }
    if (!our) a.pb(cnt);
  }
  sx = 1;
  for (int j = x; t[j] != -1; j = t[j])
    ++sx;
  k = a.size();

  d[0][0] = 1;
  forn(i, k) {
    forn(j, n+1) if (d[i][j])
      d[i+1][j+a[i]] = d[i+1][j] = 1;
    //forn(j, n+1) cout << d[i][j] << " "; cout << endl;
  }

  forn(i, n+1) if (d[k][i]) cout << i + sx << "\n";
}

int main()
{
  //freopen("input.txt", "r", stdin);

  scan();
  solve();

  return 0;
}