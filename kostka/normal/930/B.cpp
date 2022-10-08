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

vector <string> pos;
int n;

double solve(vi& group) {
  double szansa = 0;
  for(int i=0; i<n; i++) {
    map <char, int> lit;
    for(auto g : group) {
      lit[pos[g][i]]++;
    }
    double zgadne = 0;
    for(auto ele : lit) {
      zgadne += (ele.second == 1) ? 1 : 0;
    }
    szansa = max(szansa, zgadne);
  }
  return szansa;
}

int main()
{
  ios_base::sync_with_stdio(0);
  string x;
  cin >> x;
  n = SZ(x);
  for(int i=0; i<n; i++) {
    pos.push_back(x);
    rotate(x.begin(), x.begin()+1, x.end());
  }
  sort(pos.begin(), pos.end());
  int res = 0;
  for(int i=0; i<n; i++) {
    vi group = {i};
    while(i+1 < n and pos[i][0] == pos[i+1][0]) {
      group.push_back(++i);
    }
    res += solve(group);
  }
  cout << fixed << setprecision(15) << 1.0*res/n << "\n";
  return 0;
}