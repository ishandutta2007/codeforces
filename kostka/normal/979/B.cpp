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

int q;

int score(string &s) {
  map <char, int> M;
  for(auto ss : s) {
    M[ss]++;
  }
  int res = 0;
  for(auto e : M) {
    res = max(res, e.y);
  }
  if(res == SZ(s) and q == 1) return res-1;
  return min(res + q, SZ(s));
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> q;
  string s[3];
  int sc[3];
  for(int i=0; i<3; i++) cin >> s[i];
  for(int i=0; i<3; i++) sc[i] = score(s[i]);
  if(sc[0] > sc[1] and sc[0] > sc[2]) {
    cout << "Kuro\n";
  } else if(sc[1] > sc[0] and sc[1] > sc[2]) {
    cout << "Shiro\n";
  } else if(sc[2] > sc[1] and sc[2] > sc[0]) {
    cout << "Katie\n";
  } else {
    cout << "Draw\n";
  }
  return 0;
}