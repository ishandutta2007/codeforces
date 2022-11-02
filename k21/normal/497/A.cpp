#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define DEBUG(x) cerr << '>' << #x << ':' << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a) for(int i=0; i<(a);++i)
inline bool EQ(double a, double b) {return fabs(a-b) < 1e-9;}

const int INF = 1<<29;
typedef long long ll;

const int MAXN = 1200;

int N, M;

char table[MAXN][MAXN];

vector<vector<int>> check(int col, const vector<vector<int>>& groups) {
  vector<vector<int>> ngroups;
  for (const vector<int>& group : groups) {
    char last = '\0';
    vector<int> ngroup;
    for (int line : group) {
      if (table[line][col] < last) {
        return vector<vector<int>>();
      } else if (last != '\0' && last != table[line][col]) {
        ngroups.push_back(ngroup);
        ngroup.clear();
      }
      ngroup.push_back(line);
      last = table[line][col];
    }
    ngroups.push_back(ngroup);
  }
  return ngroups;
}

int main() {
	scanf("%d%d ", &N, &M);

  REP(i,N) {
    gets(table[i]);
  }
  
  int n = 0;
  vector<vector<int>> groups;
  groups.emplace_back();
  REP(i,N) groups.back().push_back(i);
  REP(i,M) {
    vector<vector<int>> ngroups = check(i, groups);
    if (ngroups.empty()) {
      ++n;
    } else {
      groups = ngroups;
    }
  }
  
  printf("%d\n", n);

	return 0;
}