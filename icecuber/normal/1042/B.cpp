#include <iostream>

using namespace std;

int best[8];
int main() {
  for (int i = 0; i < 8; i++) best[i] = 1e8;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int cost;
    string s;
    cin >> cost >> s;
    int r = 0;
    for (int j = 0; j < s.size(); j++) {
      r |= 1<<(s[j]-'A');
    }
    best[r] = min(best[r], cost);
  }
  for (int i = 0; i < 8; i++)
    for (int j = 0; j < 8; j++)
      if ((i&j) == j) best[j] = min(best[i], best[j]);
  //for (int i = 0; i < 8; i++) cout << best[i] << ' ';
  //cout << endl;
  int l[5] = {best[7], best[1]+best[2]+best[4], best[1]+best[6], best[2]+best[5], best[4]+best[3]};
  int r = 1e8;
  for (int i = 0; i < 5; i++)
    r = min(r, l[i]);
  if (r == 1e8) cout << -1 << endl;
  else cout << r << endl;
}