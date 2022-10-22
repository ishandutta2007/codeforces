#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 2e3 + 5;

int n;
char a[MAXN], b[MAXN], aa[MAXN];

vector<int> moves; // like jagger

void Rotate(int i, int x) {
  int l = x - i;
  int r = n - 1 - x;

  moves.push_back(r + 1);
  if(l) moves.push_back(l);
  moves.push_back(n);

  REP(j, i) {
    aa[j] = a[i - 1 - j];
  }
  aa[i] = a[x];
  REP(j, r) {
    aa[i + 1 + j] = a[x + 1 + j];
  }
  REP(j, l) {
    aa[i + 1 + r + j] = a[i + j];
  }

  memcpy(a, aa, sizeof a);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cin >> n;
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];


  REP(i, n) {
    int letter = b[(n - 1) / 2 + i % 2 + (i / 2) * (i % 2 ? 1 : -1)];

    int x = -1;
    FOR(j, i, n) {
      if(a[j] == letter) {
        x = j;
      }
    }
    if(x == -1) {
      cout << -1;
      return 0;
    }

    Rotate(i, x);
  }

  if(n % 2) {
    moves.push_back(n);
  }

  cout << moves.size() << "\n";
  for(auto x: moves) {
    cout << x << " ";
  }
  cout << "\n";
}