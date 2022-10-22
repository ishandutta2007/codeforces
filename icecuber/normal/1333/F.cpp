#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  vector<int> isprime(n+1,1);
  vector<int> mdiv(n+1,1);
  for (int i = 2; i <= n; i++) {
    //if (!isprime[i]) continue;
    for (int j = i*2; j <= n; j += i)
      mdiv[j] = i, isprime[j] = 0;
  }

  vector<int> p;
  for (int i = 1; i <= n; i++) {
    p.push_back(mdiv[i]);
  }
  sort(p.begin(), p.end());
  for (int i = 1; i < n; i++) cout << p[i] << ' ';
  cout << endl;
}