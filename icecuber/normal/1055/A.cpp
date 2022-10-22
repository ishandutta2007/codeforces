#include <bits/stdc++.h>
using namespace std;

int a[1000], b[1000];
void fail() {
  cout << "NO" << endl;
  exit(0);
}
void pass() {
  cout << "YES" << endl;
  exit(0);
}
int main() {
  int n, s;
  cin >> n >> s;
  s--;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  if (!a[0]) fail();
  if (a[s]) pass();
  if (!b[s]) fail();
  for (int i = s; i < n; i++)
    if (a[i] && b[i]) pass();
  fail();
}