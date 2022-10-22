#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l[100001], energy[100001], add[100001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> l[i];
  string s;
  cin >> s;
  int haswater = 0;
  ll t = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'G') {
      t += l[i]*5;
      energy[i+1] = energy[i]+l[i];
    } else if (s[i] == 'W') {
      haswater = 1;
      t += l[i]*3;
      energy[i+1] = energy[i]+l[i];
    } else {
      t += l[i];
      energy[i+1] = energy[i]-l[i];
      if (energy[i+1] < 0) {
	t += (haswater ? 3 : 5)*(-energy[i+1]);
	energy[i+1] = 0;
      }
    }
  }
  //cout << t << endl;
  for (int i = n; i; i--) {
    if (s[i-1] == 'G' && energy[i] > 0) {
      ll flylen2 = min(l[i-1]*2,energy[i]);
      t -= 4*flylen2/2;
      energy[i] -= flylen2;
      add[i+1] -= flylen2;
    }
    energy[i-1] = min(energy[i-1], energy[i]);
  }
  ll a = 0;
  for (int i = 0; i <= n; i++) {
    a += add[i];
    energy[i] += a;
  }
  //cout << t << endl;
  for (int i = n; i; i--) {
    if (s[i-1] == 'W' && energy[i] > 0) {
      ll flylen2 = min(l[i-1]*2,energy[i]);
      t -= 2*flylen2/2;
      energy[i] -= flylen2;
    }
    energy[i-1] = min(energy[i-1], energy[i]);
  }
  cout << t << endl;
}