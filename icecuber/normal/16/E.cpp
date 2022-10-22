#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double prob[1<<18];
double p[18][18];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> p[i][j];

  prob[(1<<n)-1] = 1;
  for (int i = (1<<n)-1; i; i--) {
    int pop = __builtin_popcount(i);
    double f = prob[i]*2./(pop*(pop-1));
    for (int a = 0; a < n; a++) {
      if (!(i>>a&1)) continue;
      for (int b = 0; b < a; b++) {
	if (!(i>>b&1)) continue;
	prob[i^1<<a] += f*p[b][a];
	prob[i^1<<b] += f*p[a][b];
      }
    }
  }
  for (int i = 0; i < n; i++)
    cout << setprecision(20) << prob[1<<i] << ' ';
  cout << endl;
}