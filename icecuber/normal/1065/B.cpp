#include <iostream>

using namespace std;

int main() {
  long long n, m;
  cin >> n >> m;
  long long r = 0;
  for (; r*(r-1)/2 < m; r++);
  cout << max(0LL,n-m*2) << ' ' << n-r << endl;
}