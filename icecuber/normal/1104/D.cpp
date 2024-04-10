#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ask(ll a, ll b) {
  cout << "? " << a << ' ' << b << endl;
  cout.flush();
  string ans;
  cin >> ans;
  if (ans == "e") exit(0);
  return ans == "y";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  while (1) {
    string s;
    cin >> s;
    if (s != "start") break;
    ll low = 1;

    while (low <= 1e9) {
      if (ask(low*2,low)) break;
      low *= 2;
    }
    if (low > 1e9) {
      cout << "! 1" << endl;
      continue;
    }
    ll high = low*2+1;
    low++;
    while (low+1 < high) {
      ll mid = low+high>>1;
      if (ask((mid-1)/2,mid-1)) low = mid;
      else high = mid;
    }
    cout << "! " << low << endl;
  }
}