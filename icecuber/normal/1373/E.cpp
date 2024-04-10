#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(int x, int k) {
  int ans = 0;
  for (int i = x; i <= x+k; i++) {
    for (char c : to_string(i))
      ans += c-'0';
  }
  return ans;
}

int mem[151][10];
void init() {
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 1e5; i++) {
      int s = f(i,k);
      if (s <= 150 && mem[s][k] == 0)
	mem[s][k] = i+1;
    }
  }
}
int brute(int n, int k) {
  return mem[n][k]-1;

  for (int i = 0; i < 1e5; i++) {
    if (f(i,k) == n) return i;
  }
  return -1;
}

string solve(int n, int k) {
  int b = brute(n, k);
  if (b != -1) return to_string(b);

  if (k == 0) {
    string ans;
    if (n%9) ans += to_string(n%9);
    for (int i = 0; i < n/9; i++)
      ans += '9';
    return ans;
  } else if (k == 1) {
    if (n%2) {
      if (n > 17) {
	return solve((n-(8+9))/2,0)+'8';
      } else return "-1";
    } else {
      if (n > 8+9+9) {
	return solve((n-(8+9+9))/2,0)+"89";
      } else return "-1";
    }
  } else if (k == 2) {
    if (n%3 == 0 && n > 7+8+9)
      return solve((n-(7+8+9))/3,0)+"7";
    else return "-1";
  } else return "-1";
}

int main() {
  init();
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
  }
  return 0;
  vector<int> mi(151,-1);
  int k = 3;
  for (int i = 0; i < 1e5; i++) {
    int s = f(i,k);
    if (mi[s] == -1) mi[s] = i;
  }
  for (int i = 0; i <= 150; i++) {
    cout << mi[i] << ' ';
  }
  cout << endl;
}