#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

string getString(int x) {
  char a = (x / 26) + 'A';
  char b = (x % 26) + 'a';
  return string(1, a) + string(1, b);
}

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  
  vector<string> v;
  REP(i, k-1) {
    v.push_back(getString(i));
  }
  FOR(i, k-1, n) {
    char buff[11];
    scanf("%s", buff);
    if (buff[0] == 'Y') {
      v.push_back(getString(i));
    } else {
      v.push_back(v[i-k+1]);
    }
  }

  REP(i, n) printf("%s ", v[i].c_str());
  printf("\n");
  return 0;
}