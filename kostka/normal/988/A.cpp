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
  vector <pii> A;
  for(int i=1; i<=n; i++) {
    int a;
    cin >> a;
    A.emplace_back(a,i);
  }
  sort(A.begin(), A.end());
  vi R;
  for(int i=0; i<n; i++) {
    R.push_back(A[i].y);
    while(i+1 < n and A[i].x == A[i+1].x) i++;
  }
  if(SZ(R) < k) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for(int i=0; i<k; i++) cout << R[i] << " ";
    cout << "\n";
  }
  return 0;
}