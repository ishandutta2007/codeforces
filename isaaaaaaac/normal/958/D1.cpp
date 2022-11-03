#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

const int N = 200005;

map <double, int> tmp;
double a[N];

inline double read() {
  char ch;
  int a = 0, b = 0;
  while (!isdigit(ch = getchar()));
  do {
    a = a * 10 + ch - '0';
  } while(isdigit(ch = getchar()));
  while (!isdigit(ch = getchar()));
  do {
    b = b * 10 + ch - '0';
  } while(isdigit(ch = getchar()));
  a += b; b = 0;
  while (!isdigit(ch = getchar()));
  do {
    b = b * 10 + ch - '0';
  } while(isdigit(ch = getchar()));  
  return 1.0 * a / b;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i ++)
    tmp[a[i] = read()] ++;
  for (int i = 1; i <= n; i ++) printf("%d ", tmp[a[i]]);
  puts("");
  return 0;
}