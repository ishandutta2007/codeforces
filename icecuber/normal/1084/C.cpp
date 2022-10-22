#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9+7;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  vector<int> v;
  v.push_back(0);
  string s;
  cin >> s;
  for (char c : s) {
    if (c == 'a')
      v[v.size()-1]++;
    else if (c == 'b')
      v.push_back(0);
  }
  ll ans = 1;
  for (int i : v)
    ans = ans*(i+1)%mod;
  cout << ((ans-1)%mod+mod)%mod << endl;
}