#include <iostream>
#include <vector>

using namespace std;

int a[2000];
int b[2000];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i-1] = a[i]-a[i-1];
  }
  vector<int> v;
  for (int k = 1; k <= n; k++) {
    int ok = 1;
    for (int j = 0; j < n; j++) {
      if (b[j] != b[j%k]) ok = 0;
    }
    if (ok) v.push_back(k);
  }
  cout << v.size() << endl;
  for (int i : v)
    cout << i << ' ';
  cout << endl;
}