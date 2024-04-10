#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-10;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    array<double,3> P;
    double v;
    cin >> P[0]>>P[1]>>P[2] >> v;
    map<array<double,3>,double> mem;
    function<double(array<double,3>)> f = [&](array<double,3> p) {
      if (!mem.count(p)) {
        for (int i : {0,1,2}) {
          if (p[i] <= eps) continue;
          double e = 1;
          array<double,3> np = p;
          if (i < 2) {
            double take = min(p[i],v);
            np[i] -= take;
            double add = take/((p[!i]>eps)+1);
            np[2] += add;
            if (p[!i] > eps)
              np[!i] += add;
            e = f(np)+1;
          }
          mem[p] += p[i]*e;
        }
      }
      return mem[p];
    };
    cout << setprecision(20) << f(P) << endl;
  }
}