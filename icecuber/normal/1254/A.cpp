#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string row[100];
char ans[100][100];
string alpha = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

int main() {
  assert(alpha.size() == 62);
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int h, w, k;
    cin >> h >> w >> k;
    int rice = 0;
    for (int i = 0; i < h; i++) {
      cin >> row[i];
      for (int j = 0; j < w; j++)
	rice += (row[i][j] == 'R');
    }
    vector<int> order;
    for (int j = 0; j < w; j++) order.push_back(j);

    int acc = 0;
    for (int i = 0; i < h; i++) {
      for (int j : order) {
	ans[i][j] = alpha[min(acc*k/rice,k-1)];
	acc += (row[i][j]=='R');
      }
      reverse(order.begin(), order.end());
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
	cout << ans[i][j];
      }
      cout << '\n';
    }
  }
}