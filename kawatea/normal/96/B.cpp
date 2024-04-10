#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  long long n, m;
  int c = 0, f = 0, i;

  cin >> n;

  m = n;

  while (m) {
    m /= 10;
    c++;
  }

  if (c % 2 == 0) {
    vector<int> v;

    for (i = 0; i < c / 2; i++) {
      v.push_back(4);
      v.push_back(7);
    }

    sort(v.begin(), v.end());

    do {
      m = 0;

      for (i = 0; i < c; i++) m = m * 10 + v[i];

      if (m >= n) {
	n = m; f = 1; break;
      }
    } while (next_permutation(v.begin(), v.end()));
  }

  if (f == 0) {
    m = 0;

    if (c % 2 == 0) c++;

    for (i = 0; i <= c / 2; i++) m = m * 10 + 4;
    for (; i <= c; i++) m = m * 10 + 7;

    n = m;
  }

  cout << n << endl;

  return 0;
}