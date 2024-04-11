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
  vi a(n);
  for(int i=0; i<n; i++) cin >> a[i];
  reverse(a.begin(), a.end());
  vi b;
  set <int> S;
  for(auto aa : a) {
    if(S.find(aa) == S.end()) b.push_back(aa);
    S.insert(aa);
  }
  reverse(b.begin(), b.end());
  cout << SZ(b) << "\n";
  for(auto bb : b) cout << bb << " ";
  cout << "\n";
  return 0;
}