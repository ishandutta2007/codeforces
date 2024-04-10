#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

int prep[50];

const int MAX = (1 << 20) - 1;



int main() {

  int p = 3, ind = 2;
  while(p <= MAX) {
    FOR(i, 1, p) {
      prep[ind] = max(prep[ind], __gcd(p & i, p ^ i));
    }

    ind ++;
    p *= 2;
    p ++;
  }

  prep[25] = 1082401;
  prep[24] = 5592405;
  prep[23] = 178481;
  prep[22] = 1398101;
  prep[21] = 299593;
  prep[20] = 349525;
  prep[18] = 87381;



  int q; cin >> q;
  REP(i, q) {
    int x; cin >> x;
    int k = 1, jj = 0;;
    while(k <= x) {
      k *= 2;
      jj ++;
    }

    if(x == k - 1) {
      cout << max(prep[jj], 1) << endl;
    }
    else {


    cout << k - 1 << endl;
  }}
}