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
  int n, m;
  cin >> n >> m;
  bool swapped = false;
  if(n == 1 and m == 1) {
    cout << "YES\n1\n";
    return 0;
  }
  if(n == 3 and m == 3) {
    cout << "YES\n5 9 7\n3 4 2\n1 6 8\n";
    return 0;
  } if(max(n,m) < 4) {
    cout << "NO\n";
    return 0;
  } if(n > m) {
    swap(n, m);
    swapped = true;
  }
  vector <vector <int> > A(n);
  for(int i=0; i<n; i++) A[i].resize(m);
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      if(swapped) A[i][j] = j * n + (i+1);
      else A[i][j] = i * m + (j+1);
    }
  }
  auto B = A;
  for(int i=0; i<n; i++) {
    vector <int> W[2];
    for(int j=0; j<m/2*2; j++) {
      W[j<m/2].push_back(A[i][j]);
    }
    if(i%2) {
      swap(W[0], W[1]);
      reverse(W[0].begin(), W[0].end());
      reverse(W[1].begin(), W[1].end());
    }
    vector <int> Y;
    for(int j=0; j<m/2*2; j++) {
      if(i%2 == 0 and j == 1 and m%2 == 1) Y.push_back(A[i][m-1]);
      if(i%2 == 1 and j == 0 and m%2 == 1) Y.push_back(A[i][m-1]);
      Y.push_back(W[j%2][j/2]);
    }
    for(int j=0; j<m; j++) B[i][j] = Y[j];
  }
  cout << "YES\n";
  if(!swapped) {
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) cout << B[i][j] << " ";
      cout << "\n";
    }
  } else {
    for(int i=0; i<m; i++) {
      for(int j=0; j<n; j++) cout << B[j][i] << " ";
      cout << "\n";
    }
  }
  return 0;
}