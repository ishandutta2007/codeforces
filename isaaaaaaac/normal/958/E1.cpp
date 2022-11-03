#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int N = 105;

int n, m;

int main() {
  scanf("%d%d", &n, &m);
  puts(n == m ? "Yes" : "No");
  return 0;
}