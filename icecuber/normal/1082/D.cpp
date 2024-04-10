#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int,int> a[500];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    sum += a[i].first;
  }
  if (sum < 2*n-2) {
    cout << "NO" << endl;
    return 0;
  }
  sort(a,a+n);
  int ones = 0;
  while (ones < n && a[ones].first == 1) ones++;
  if (ones < 2) ones = 2;
  //cout << ones << ' ' << n-ones << endl;
  cout << "YES " << n+1-ones << endl;
  cout << n-1 << endl;
  cout << a[0].second+1 << ' ' << a[ones].second+1 << endl;
  cout << a[1].second+1 << ' ' << a[n-1].second+1 << endl;
  a[ones].first--;
  a[n-1].first--;
  for (int i = ones+1; i < n; i++) {
    cout << a[i-1].second+1 << ' ' << a[i].second+1 << endl;
    a[i-1].first--;
    a[i].first--;
  }
  int j = ones;
  for (int i = 2; i < ones; i++) {
    while (!a[j].first) j++;
    cout << a[i].second+1 << ' ' << a[j].second+1 << endl;
    a[j].first--;
  }
}