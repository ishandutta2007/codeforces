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
  set <pair <int, int> > I, E;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    I.emplace(x, i);
  }
  string x;
  cin >> x;
  for(auto xx : x) {
    if(xx == '0') {
      auto it = *I.begin();
      cout << it.y + 1 << " ";
      I.erase(it);
      E.insert(it);
    } else {
      auto it = *E.rbegin();
      cout << it.y + 1 << " ";
      E.erase(it);
    }
  }
  return 0;
}