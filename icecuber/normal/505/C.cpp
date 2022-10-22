#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m = 30001;
int gems[m];
int mem[m][300];

int mind;
int rec(int p, int last) {
  if (p >= m) return 0;
  int&memo = mem[p][last-mind];
  if (!memo) {
    int ans = 0;
    for (int d : {last-1, last, last+1}) {
      if (d < 1) continue;
      ans = max(ans, rec(p+d,d));
    }
    memo = 1+gems[p]+ans;
  }
  return memo-1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, d;
  cin >> n >> d;
  mind = d;
  int p = 0;
  while (mind >= 1 && p < m) p += mind--;
  for (int i = 0; i < n; i++) {
    int p;
    cin >> p;
    gems[p]++;
  }
  cout << rec(d,d) << endl;
}