#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<int,int> a[1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a+n, greater<pair<int,int>>());
  int need = 0;
  for (int i = 0; i < n; i++) {
    need += a[i].first*i+1;
  }
  cout << need << endl;
  for (int i = 0; i < n; i++)
    cout << a[i].second+1 << ' ';
  cout << endl;
}