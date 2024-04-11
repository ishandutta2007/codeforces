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
  int k;
  cin >> k;
  vector <vi> A(k);
  vector <pii> P;
  for(int i=0; i<k; i++) {
    int x;
    cin >> x;
    int sum = 0;
    for(int j=0; j<x; j++) {
      int y;
      cin >> y;
      A[i].push_back(y);
      sum += y;
    }
    for(int j=0; j<x; j++) {
      A[i][j] = sum - A[i][j];
      P.emplace_back(A[i][j], i);
    }
  }
  sort(P.begin(), P.end());
  P.resize(distance(P.begin(), unique(P.begin(), P.end())));
  for(int i=1; i<SZ(P); i++) {
    if(P[i].x == P[i-1].x) {
      cout << "YES\n";
      for(int a=0; a<SZ(A[P[i].y]); a++) {
        if(A[P[i].y][a] == P[i].x) {
          cout << P[i].y + 1 << " " << a+1 << "\n";
          break;
        }
      }
      for(int a=0; a<SZ(A[P[i-1].y]); a++) {
        if(A[P[i-1].y][a] == P[i-1].x) {
          cout << P[i-1].y + 1 << " " << a+1 << "\n";
          break;
        }
      }
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}