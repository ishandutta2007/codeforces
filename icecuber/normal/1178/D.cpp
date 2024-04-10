#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m = 2000;
int isprime[m];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  for (int i = 2; i < m; i++) isprime[i] = 1;
  for (int i = 2; i < m; i++) {
    if (!isprime[i]) continue;
    for (int j = i*2; j < m; j += i)
      isprime[j] = 0;
  }
  /*for (int i = 3; i <= 1000; i++) {
    int ok = 0;
    for (int j = i; j <= i+i/2; j++)
      if (isprime[j]) ok = 1;
    if (!ok) cout << i << endl;
    }*/
  int n;
  cin >> n;
  int m = n;
  while (!isprime[m]) m++;
  cout << m << endl;
  for (int i = 0; i < n; i++)
    cout << i+1 << ' ' << (i+1)%n+1 << endl;
  for (int i = 0; i < m-n; i++)
    cout << i+1 << ' ' << i+n/2+1 << endl;
}