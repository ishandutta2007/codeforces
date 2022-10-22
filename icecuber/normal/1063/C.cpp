#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll mi = 10, ma = 2e9-10;
  for (int i = 0; i < n; i++) {
    ll mid = mi+ma>>1;
    cout << mid/2 << ' ' << (mid+1)/2 << endl;
    //cerr << mid << endl;
    string s;
    cin >> s;
    if (s == "black") mi = mid+1;
    else ma = mid-1;
  }
  if (ma%2) {
    cout << ma/2 << ' ' << ma/2+2 << ' ';
    cout << ma/2+1 << ' ' << ma/2 << endl;
  } else {
    cout << ma/2-1 << ' ' << ma/2+1 << ' ';
    cout << ma/2+1 << ' ' << ma/2 << endl;
  }
  //cerr << mi << ' ' << ma << endl;
}