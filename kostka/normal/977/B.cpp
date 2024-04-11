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
  map <string, int> dwu;
  int n;
  cin >> n;
  string x;
  cin >> x;
  for(int i=1; i<n; i++) {
    dwu[x.substr(i-1, 2)]++;
  }
  int maks = -1;
  for(auto ele : dwu) {
    maks = max(maks, ele.second);
  }
  for(auto ele : dwu) {
    if(ele.second == maks) {
      cout << ele.first << "\n";
      return 0;
    }
  }
}