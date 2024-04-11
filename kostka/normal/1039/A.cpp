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
  ll t;
  cin >> n >> t;
  vector <ll> A(n+1);
  for(int i=1; i<=n; i++) {
    cin >> A[i];
  }
  vector <ll> B = A;
  for(int i=1; i<=n; i++) B[i] += t;
  vi P(n+1);
  for(int i=1; i<=n; i++) cin >> P[i];
  for(int i=1; i<=n; i++) {
    if(P[i] < i) {
      cout << "No\n";
      return 0;
    }
  }
  for(int i=2; i<=n; i++) {
     if(P[i] < P[i-1]) {
       cout << "No\n";
       return 0;
     }
     if(i <= P[i-1]) B[i-1] = A[i] + t;
  }
  for(int i=2; i<=n; i++) if(B[i-1] + 1 > B[i]) B[i] = B[i-1] + 1;
  for(int i=1; i<=n; i++) {
    if(P[i] != n and A[P[i]+1] + t <= B[P[i]]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  for(int i=1; i<=n; i++) cout << B[i] << " ";
  cout << "\n";
  return 0;
}