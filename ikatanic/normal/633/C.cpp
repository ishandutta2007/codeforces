#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1101000;
const int MAXM = 100010;

int t[MAX][26];
bool fin[MAX];
int id[MAX];
char s[MAX];
string w[MAXM];

int alloc = 1;

void insert(int x, char* s, int i) {
  if (*s == 0) {
    fin[x] = true;
    id[x] = i;
    return;
  }

  int c = tolower(*s) - 'a';
  if (t[x][c] == 0) t[x][c] = alloc++;
  insert(t[x][c], s + 1, i);
}

int main(void) {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  reverse(s, s + n);
  
  int m;
  scanf("%d", &m);
  
  int root = alloc++;
  REP(i, m) {
    static char b[MAXM];
    scanf("%s", b);
    insert(root, b, i);
    w[i] = b;
  }

  static int f[MAXM];
  REP(i, n+1) f[i] = -1;
  f[0] = 0;
  REP(i, n) {
    if (f[i] == -1) continue;
    int cur = root;
    int j = i;
    while (j < n && t[cur][s[j]-'a']) {
      cur = t[cur][s[j]-'a'];
      if (fin[cur]) f[j+1] = id[cur];
      j++;
    }
  }

  assert(f[n] != -1);
  while (n > 0) {
    printf("%s", w[f[n]].c_str());
    n -= w[f[n]].size();
    if (n > 0) putchar(' ');
  }
  printf("\n");
  return 0;
}