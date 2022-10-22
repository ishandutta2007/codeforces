#include <iostream>
#include <algorithm>

using namespace std;

int a[400000];
int prefix[400000];
int odd[400000], even[400000];

int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long long v;
    cin >> v;
    while (v) {
      a[i] += (v&1);
      v >>= 1;
    }
  }
  prefix[0] = a[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i-1]+a[i];
  }
  for (int i = 0; i < n; i++) {
    even[i+1] = even[i]+(prefix[i]%2==0);
    odd[i+1] = odd[i]+(prefix[i]%2);
  }

  long long ok = 0;
  for (int i = 0; i < n; i++) {
    int sum = 0, ma = 0;
    int j = i;
    for (; sum < 130 && j < n; j++) {
      sum += a[j];
      ma = max(ma, a[j]);
      if (sum >= ma*2 && !(sum&1)) ok++;
    }
    if (j < n) {
      if (i && prefix[i-1]%2) {
	ok += odd[n]-odd[j];
      } else {
	ok += even[n]-even[j];
      }
    }
  }
  cout << ok << endl;
}