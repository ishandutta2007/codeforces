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

bool substr(string a, string b) {
  for(int i=0; i<SZ(b)-SZ(a)+1; i++) {
    if(b.substr(i, SZ(a)) == a) return true;
  }
  return false;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector <string> X(n);
  for(int i=0; i<n; i++) {
    cin >> X[i];
  }
  sort(X.begin(), X.end(), [](string& a, string &b){
    if(SZ(a) != SZ(b)) return SZ(a) <= SZ(b);
    return a < b;
  });
  for(int i=1; i<n; i++) {
    if(!substr(X[i-1], X[i])) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "YES\n";
  for(auto x : X) cout << x << "\n";
  return 0;
}