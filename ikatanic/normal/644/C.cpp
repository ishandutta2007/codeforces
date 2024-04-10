#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

map<string, vector<string>> paths;
map<vector<string>, vector<string>> groups;

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    char s[100];
    scanf("%s", s);
    string hostname = "";
    int pos = 0, cnts = 0;
    int len = strlen(s);
    while (pos < len) {
      if (s[pos] == '/') cnts++;
      if (cnts == 3) break;
      hostname.push_back(s[pos++]);
    }

    paths[hostname].push_back(s + pos);
  }
  
  for (auto& p: paths) {
    sort(p.second.begin(), p.second.end());
    p.second.erase(unique(p.second.begin(), p.second.end()), p.second.end());
    groups[p.second].push_back(p.first);
  }

  int cnt = 0;
  for (auto& g: groups) 
    cnt += (int)g.second.size() > 1;

  printf("%d\n", cnt);
  for (auto& g: groups) {
    if (g.second.size() == 1) continue;
    for (auto& s: g.second) printf("%s ", s.c_str());
    putchar('\n');
  }
  return 0;
}