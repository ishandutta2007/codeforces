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

int n, L;
vector <ll> A[2];

ll val(int d, int e) {
  return A[d][e%n] + 1LL * e/n * L;
}

bool check(int x) {
  vector <ll> D[2*n];
  int p = 0, k = 0;
  for(int i=0; i<n; i++) {
    while(val(0, i+n) > val(1, p) + x) p++;
    while(k < p + n - 1 and val(1, k+1) <= val(0, i+n) + x) k++;
    if(max(abs(val(1,p) - val(0,i+n)), abs(val(1,k) - val(0,i+n))) > x) return false;
    int pp = p, kk = k;
    while(min(pp, kk) >= n) {
      pp -= n; kk -= n;
    }
    D[pp].push_back(kk);
    if(max(pp, kk) < n) {
      D[pp+n].push_back(kk+n);
    }
  }
  priority_queue<int, vector<int>, greater<int>> Q;
  for(int i=0; i<2*n; i++) {
    for(auto w : D[i]) Q.push(w);
    if(!Q.empty()) {
      // cerr << i << " " << Q.top() << "\n";
      if(Q.top() < i) return false;
      Q.pop();
    }
  }
  return Q.empty();
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n >> L;
  A[0].resize(n);
  A[1].resize(n);
  for(int i=0; i<n; i++) cin >> A[0][i];
  for(int i=0; i<n; i++) cin >> A[1][i];
  sort(A[0].begin(), A[0].end());
  sort(A[1].begin(), A[1].end());
  int p = -1, k = L+1;
  while(k-p > 1) {
    int m = (p+k)>>1;
    if(check(m)) {
      // cerr << "OK\n";
      k = m;
    }
    else p = m;
  }
  cout << k << "\n";
  return 0;
}