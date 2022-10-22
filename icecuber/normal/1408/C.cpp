#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    a.insert(a.begin(), 0);
    a.push_back(l);
    n += 2;

    vector<double> x(n);
    for (int i = 0; i+1 < n; i++) {
      x[i+1] = x[i]+(a[i+1]-a[i])*1./(i+1);
    }
    vector<double> y(n);
    for (int i = n-1; i >= 1; i--) {
      y[i-1] = y[i]+(a[i]-a[i-1])*1./(n-i);
    }
    {
      int j = 1;
      while (x[j] <= y[j]) j++;
      j--;
      //(ans-x[j])*(j+1)+(ans-y[j+1])*(n-j) = a[j+1]-a[j];
      cout << setprecision(20) << ((a[j+1]-a[j])+x[j]*(j+1)+y[j+1]*(n-j-1))/(n) << endl;
    }
  }
}