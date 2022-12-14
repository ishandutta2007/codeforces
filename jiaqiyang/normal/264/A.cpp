#include <cstdio>
#include <cstring>
#include <list>

const int N = 1000000 + 10;

char s[N];
std::list<int> cur;

int main() {
  scanf(" %s", s);
  std::list<int>::iterator p = cur.begin();
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    p = cur.insert(p, i + 1);
    if (c == 'r') ++p;
  }
  for (std::list<int>::iterator it = cur.begin(); it != cur.end(); ++it) printf("%d\n", *it);
  return 0;
}