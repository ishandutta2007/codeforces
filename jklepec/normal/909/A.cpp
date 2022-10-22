#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

vector <string> v;

int main() {
  string a, b; cin >> a >> b;

  FOR(i, 1, a.size() + 1) FOR(j, 1, b.size() + 1) {
    v.push_back(a.substr(0, i) + b.substr(0, j));
  }

  sort(v.begin(), v.end());

  cout << v[0];
}