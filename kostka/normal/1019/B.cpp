//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

const int MAXN = 100007;
bool vis[MAXN];
int mem[MAXN];

int limit = 0;

int ask(int q) {
  if(vis[q]) return mem[q];
  if(++limit > 60) {
    cout << "! " << -1 << endl;
    exit(0);
  }
  vis[q] = true;
  cout << "? " << q << endl;
  cin >> mem[q];
  return mem[q];
}

bool check(int q, int n) {
  int dr = q + n/2;
  if(dr > n) dr -= n;
  int oa = ask(q), ob = ask(dr);
  if(oa == ob) {
    cout << "! " << q << endl;
    exit(0);
  }
  return (oa < ob) == (ask(1) < ask(n/2+1));
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  if(ask(1) == ask(n/2+1)) {
    cout << "! " << 1 << endl;
    return 0;
  }
  int p = 1, q = n/2+1;
  while(q - p > 1) {
    int m = (p + q) >> 1;
    if(check(m, n)) p = m;
    else q = m;
  }
  cout << "! " << -1 << endl;
  return 0;
}