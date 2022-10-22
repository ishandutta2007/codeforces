#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[50];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  sort(a, a+n);
  int losing = 1;
  for (int j = 0; j < n/2; j++)
    if (a[j] != a[j+1]) losing = 0;
  cout << (losing ? "Bob" : "Alice") << endl;
}