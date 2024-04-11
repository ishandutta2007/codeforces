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

int foo(char a, char b, char c, char d) {
  vector <char> C = {a, b, c, d};
  sort(C.begin(), C.end());
  map <char, int> M;
  for(auto c : C) M[c]++;
  if(SZ(M) == 1) return 0;
  if(SZ(M) == 2) {
    if(C[0] == C[1] and C[2] == C[3]) return 0;
    else return 1;
  }
  if(SZ(M) == 3) {
    if(a != c) return 1;
    else return 2;
  }
  return 2;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int ret = 0;
  for(int i=0; i<n/2; i++) {
    ret += foo(a[i], b[i], a[n-i-1], b[n-i-1]);
  }
  if(n%2 and a[n/2] != b[n/2]) ret++;
  cout << ret << "\n";
  return 0;
}