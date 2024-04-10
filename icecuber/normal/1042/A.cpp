#include <iostream>
#include <cmath>

using namespace std;

int a[100];
int main() {
  int n, m;
  cin >> n >> m;
  int ma = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ma = max(a[i], ma);
    sum += a[i];
  }
  cout << max(((m-(n*ma-sum))+n-1)/n+ma, ma) << ' ' << ma+m << endl;
}