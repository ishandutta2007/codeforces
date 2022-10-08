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
  vector <string> S(n);
  vector <int> A(m);
  for(int i=0; i<n; i++) {
    cin >> S[i];
    for(int j=0; j<m; j++) {
      if(S[i][j] == '1') A[j]++;
    }
  }
  for(int i=0; i<n; i++) {
    bool ok = true;
    for(int j=0; j<m; j++) {
      if(A[j] == 1 and S[i][j] == '1') ok = false;
    }
    if(ok) {
      puts("YES");
      exit(0);
    }
  }
  puts("NO");
  return 0;
}