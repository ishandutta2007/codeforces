//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  if(n == 1) {
    cout << "Yes\n";
    return 0;
  }
  string x;
  cin >> x;
  map <char, int> M;
  for(auto c : x) M[c]++;
  for(auto e : M) if(e.y >= 2) {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
  return 0;
}