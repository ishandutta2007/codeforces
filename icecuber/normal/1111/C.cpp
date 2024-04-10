#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B;
ll solve(vector<int> x, int n) {
  if (x.size() == 0) return A;
  ll ans = x.size()*(1ll<<n)*B;
  if (!n) return ans;
  vector<int> left, right;
  for (int i : x) {
    if (i <= (1<<n-1)) left.push_back(i);
    else right.push_back(i-(1<<n-1));
  }
  ans = min(ans, solve(left, n-1)+solve(right, n-1));
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k >> A >> B;
  vector<int> avengers;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    avengers.push_back(x);
  }
  cout << solve(avengers, n) << endl;
}