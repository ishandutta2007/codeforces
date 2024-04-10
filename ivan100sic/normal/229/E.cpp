// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
set<int> s[1005];
map<int, int> sve;

double bp[1005][1005];
int chosen[1005];

void init() {
  for (int i=0; i<=1001; i++) {
    bp[i][i] = 1;
    bp[i][0] = 1;
  }

  for (int l=1; l<=1001; l++) {
    for (int i=1; i<l; i++) {
      bp[l][i] = 1.0 / (1.0 / bp[l-1][i] + 1.0 / bp[l-1][i-1]);
    }
  }
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  init();

  cin >> n >> m;

  for (int i=0; i<m; i++) {
    int k;
    cin >> k;
    for (int j=0; j<k; j++) {
      int x;
      cin >> x;
      s[i].insert(x);
      sve[x]++;
    }
  }

  int lowval = 0, lowcnt = 0;
  {
    int t = n;
    auto it = --sve.end();
    while (1) {
      if (t <= it->second) {
        lowval = it->first;
        lowcnt = t;
        break;
      } else {
        t -= it->second;
        --it;
      }
    }
  }

  // cerr << "low params = " << lowval << ' ' << lowcnt << '\n';

  for (int i=0; i<m; i++) {
    chosen[i] = count_if(begin(s[i]), end(s[i]), [&](int x) { return x > lowval; });
    // cerr << "chosen = " << chosen[i] << '\n';
  }

  int havelow = 0;
  for (int i=0; i<m; i++) {
    havelow += s[i].count(lowval);
  }

  vector<double> ol(1005);
  ol[0] = 1;

  for (int i=0; i<m; i++) {
    vector<double> nu(1005);
    // stari broj extra izabranih
    for (int j=0; j<=i; j++) {
      double pc = 0;
      if (j < lowcnt && s[i].count(lowval)) {
        pc = double(lowcnt - j) / havelow;
      }


      // cerr << "pc = " << pc << '\n';

      // izabracu jednog sad
      nu[j+1] += ol[j] * pc * bp[s[i].size()][chosen[i] + 1];
      // necu
      nu[j] += ol[j] * (1 - pc) * bp[s[i].size()][chosen[i]];
    }
    
    havelow -= s[i].count(lowval);

    // for (int j=0; j<6; j++) {
    //   cerr << nu[j] << " \n"[j == 5];
    // }

    swap(ol, nu);
  }

  cout << setprecision(20) << fixed;
  cout << ol[lowcnt] << '\n';

}