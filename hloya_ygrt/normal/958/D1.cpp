#include <bits/stdc++.h>

using namespace std;

const int N = 234567;

int gcd(int a, int b) {
  while (a && b) {
    if (a >= b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

pair<int, int> q[N];
char s[N];

int main() {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  map<pair<int, int>, int> cnt;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    int len = strlen(s);
    bool f0 = false, f1 = false;
    int a = 0, b = 0, c = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == '+') {
        f0 = true;
      }
      if (s[i] == '/') {
        f1 = true;
      }
      if (s[i] < '0' || s[i] > '9') {
        continue;
      }
      if (!f0 && !f1) {
        a = 10 * a + s[i] - '0';
      } else if (f0 && !f1) {
        b = 10 * b + s[i] - '0';
      } else {
        c = 10 * c + s[i] - '0';
      }
    }
    int F = a + b;
    int S = c;
    int h = gcd(F, S);
    F /= h;
    S /= h;
    q[i] = make_pair(F, S);
    cnt[q[i]]++;
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", cnt[q[i]]);
  }
  printf("\n");
  return 0;  
}