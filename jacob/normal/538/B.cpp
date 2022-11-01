#include <vector>
#include <iostream>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> res;
  int pw = 1;
  while (n) {
    int d = n % 10;
    n /= 10;
    if (d > res.size())
      res.resize(d);
    for (int i = 0; i < d; ++i) {
      res[i] += pw;
    }
    pw *= 10;
  }
  cout << res.size() << endl;
  for (int a : res) {
    cout << a << " ";
  }
  cout << endl;
}