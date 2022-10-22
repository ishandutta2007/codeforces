#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string mul(string a, int f) {
  string r;
  for (int i = 0; i < f; i++) r += a;
  return r;
}

const int mod = 998244353;

int BS(function<bool(int)> f, int low, int high) {
  int pass = low-1, fail = high+1;
  while (fail-pass > 1) {
    int mid = (pass+fail)/2;
    if (f(mid)) pass = mid;
    else fail = mid;
  }
  return pass-low+1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> A(n), acc(n+1), alt(n+1);
    for (int i = 0; i < n; i++) {
      cin >> A[i];
      acc[i+1] = acc[i]+A[i];
      alt[i+1] = alt[i]+(i%2?1:-1)*A[i];
    }

    ll ans = 0;
    for (int a = 2; a+2 <= n; a++) { 
      if (acc[a]-acc[0] > acc[n]-acc[a]) ans++;
    }
    for (int a = 0; a <= n; a++) {
      ans += BS([&](int b) {
        return -(acc[a]-acc[0]) + (a%2?1:-1)*(alt[a+b*2]-alt[a]) + acc[n]-acc[a+b*2] > 0;
          }, 0, (n-a)/2);
      if (a >= 3) {
        ans += BS([&](int b) {
            return A[0]-(acc[a]-acc[1]) + (a%2?1:-1)*(alt[a+b*2]-alt[a]) + acc[n]-acc[a+b*2] > 0;
          }, 0, (n-a)/2);
        if (n-a >= 3) {
          ans += BS([&](int b) {
              return A[0]-(acc[a]-acc[1]) + (a%2?1:-1)*(alt[a+b*2]-alt[a]) + acc[n-1]-acc[a+b*2] - A[n-1] > 0;
            }, 0, (n-a-3)/2);
        }
      }
      if (n-a >= 3) {
        ans += BS([&](int b) {
            return -(acc[a]-acc[0]) + (a%2?1:-1)*(alt[a+b*2]-alt[a]) + acc[n-1]-acc[a+b*2] - A[n-1] > 0;
          }, 0, (n-a-3)/2);
      }
    }
    cout << ans%mod << endl;
  }
  return 0;

  /*



  int cnt = 0;
  int n = 20;
  vector<string> s;
  for (int a = 0; a <= n; a++) {
    for (int b = 0; a+b*2 <= n; b++) {
      for (int c = 0; a+b*2+c <= n; c++) {
        if (a+b*2+c == n) 
          s.push_back( mul("0",a)+mul("10",b)+mul("1",c) );

        if (a+b*2+c == n-1 && a >= 2) 
          s.push_back( "1"+mul("0",a)+mul("10",b)+mul("1",c) );

        if (a+b*2+c == n-1 && c >= 2) 
          s.push_back( mul("0",a)+mul("10",b)+mul("1",c)+"0" );

        if (a+b*2+c == n-2 && a >= 2 && c >= 2) 
          s.push_back( "1"+mul("0",a)+mul("10",b)+mul("1",c)+"0" );

        if (a+b*2+c == n && a >= 2 && c >= 2 && b == 0) {
          s.push_back(mul("1",a)+mul("0",c));
        }
      }
    }
  }
  cout << s.size() << endl;
  sort(s.begin(), s.end());
  s.resize(unique(s.begin(), s.end())-s.begin());
  cout << s.size() << endl;

  for (int m = 0; m < 1<<n; m++) {
    vector<int> c, p;
    for (int i = 0; i < n; i++) {
      (m>>i&1 ? p : c).push_back(i);
    }
    int ok = 1;
    for (int i = 2; i < (int)c.size(); i++) {
      if (c[i-1]-c[i-2] > c[i]-c[i-1]) ok = 0;
    }
    for (int i = 2; i < (int)p.size(); i++) {
      if (p[i-1]-p[i-2] < p[i]-p[i-1]) ok = 0;
    }
    if (ok) {
      string x;
      for (int i = 0; i < n; i++) {
        x += '0'+(m>>i&1);
      }
      if (count(s.begin(), s.end(), x) == 0) cout << x << endl;
      cnt++;
    }
  }
  cout << cnt << endl;
  */
}