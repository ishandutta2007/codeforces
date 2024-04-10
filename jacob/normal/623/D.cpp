#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <queue>
#include <numeric>
#include <functional>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  if (n == 0) {
    cout << 1 << endl;
    return 0;
  }
  vector<double> p(n);
  vector<int> powers(n, 1);
  vector<double> curval(n);
  using pdi = pair<double, int>;
  priority_queue<pdi, vector<pdi>> q;
  double prob = 1.0;
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    p[i] /= 100.0;
    prob *= p[i];
    curval[i] = p[i];
    q.push(pdi((1 - pow(1 - p[i], powers[i] + 1)) / curval[i], i));
  }

  double result = n + 1 - prob;

  for (int i = 0; i < 500000; ++i) {
    //cerr << prob << endl;
    auto c = q.top();
    q.pop();
    prob /= curval[c.second];
    ++powers[c.second];
    curval[c.second] = 1 - pow(1 - p[c.second], powers[c.second]);
    prob *= curval[c.second];
    q.push(pdi((1 - pow(1 - p[c.second], powers[c.second] + 1)) / curval[c.second], c.second));
    result += 1 - prob;
  }

  cout << fixed << setprecision(20) << result << endl;


}