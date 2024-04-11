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

int main()
{
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  multiset <int> M;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    M.insert(x);
  }
  int eaten = 0;
  for(auto it = M.begin(); it != M.end(); it++) {
    auto jt = M.upper_bound(*it);
    if(jt != M.end() and (*jt) - (*it) <= k) {
      eaten++;
    }
  }
  cout << n - eaten << "\n";
  return 0;
}