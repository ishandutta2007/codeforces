#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int r = 0;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    r |= v;
  }
  if (r) cout << "HARD" << endl;
  else cout << "EASY" << endl;

}