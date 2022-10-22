#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> point;

unordered_map<int, int> pref;

ll sol;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, k; cin >> n >> k;

  pref[0] = 1;

  int sup = (1 << k) - 1;

  int tmp = 0;
  REP(i, n) {
    int x; cin >> x;
    tmp ^= x;

    if(pref[tmp] > pref[tmp ^ sup]) tmp ^= sup;
    sol += i + 1 - pref[tmp];
    pref[tmp] ++;
  }

  cout << sol;
}