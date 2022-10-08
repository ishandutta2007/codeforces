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

int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vi row(n), col(m);
  for(int i=0; i<n; i++) cin >> row[i];
  for(int i=0; i<m; i++) cin >> col[i];
  int XOR = 0;
  for(int i=0; i<n; i++) XOR ^= row[i];
  for(int i=0; i<m; i++) XOR ^= col[i];
  if(XOR != 0) {
    puts("NO");
    return 0;
  }
  vector <vi> tab(n);
  for(int i=0; i<n; i++) tab[i].resize(m);
  tab[0][0] = row[0];
  for(int i=1; i<m; i++) {
    tab[0][i] = col[i];
    tab[0][0] ^= col[i];
  }
  for(int i=1; i<n; i++) {
    tab[i][0] = row[i];
    // tab[0][0] ^= row[i];
  }
  for(int i=0; i<n; i++) {
    int chk = 0;
    for(int j=0; j<m; j++) chk ^= tab[i][j];
    assert(chk == row[i]);
  }
  for(int i=0; i<m; i++) {
    int chk = 0;
    for(int j=0; j<n; j++) chk ^= tab[j][i];
    assert(chk == col[i]);
  }
  cout << "YES\n";
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cout << tab[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}