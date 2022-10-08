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
  int n, k, l;
  cin >> n >> k >> l;
  int m = n*k;
  vector <int> A(m);
  vector <bool> taken(m);
  for(int i=0; i<m; i++) cin >> A[i];
  sort(A.begin(), A.end());
  int max = distance(A.begin(), upper_bound(A.begin(), A.end(), A[0]+l));
  cerr << max << "\n";
  if(max < n) {
    cout << "0\n";
    return 0;
  }
  vector <int> B[n];
  int kt = 0;
  for(int i=0; i<m; i++) {
    if(i == max) kt = 0;
    if(!taken[i]) {
      while(SZ(B[kt]) == k) kt++;
      while(i < max and max - i < n - kt) kt++;
      B[kt].push_back(A[i]);
    }
  }
  ll res = 0;
  for(int i=0; i<n; i++) {
    sort(B[i].begin(), B[i].end());
    res += B[i][0];
  }
  cout << res << "\n";
  return 0;
}