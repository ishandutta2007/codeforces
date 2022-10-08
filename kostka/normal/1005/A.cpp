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
#define ALL(X) x.begin(), x.end()

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
  vi A(n);
  for(int i=0; i<n; i++) cin >> A[i];
  vi R;
  for(int i=0; i+1<n; i++) if(A[i+1] == 1) R.push_back(A[i]);
  R.push_back(A.back());
  cout << SZ(R) << "\n";
  for(auto r : R) cout << r << " ";
  cout << "\n";
  return 0;
}