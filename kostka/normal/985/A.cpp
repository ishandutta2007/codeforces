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
  int n;
  cin >> n;
  vi A(n/2);
  for(int i=0; i<n/2; i++) cin >> A[i];
  sort(A.begin(), A.end());
  int a1 = 0, a2 = 0;
  for(int i=0; i<n/2; i++) {
    a1 += abs(2*i+1 - A[i]);
    a2 += abs(2*i+2 - A[i]);
  }
  cout << min(a1, a2) << "\n";
  return 0;
}