//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>

void nope() {
  puts("No");
  exit(0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  int x, y;
  cin >> x >> y;
  if(y == 0) nope();
  y--;
  if(y == 0 and x > 0) nope();
  x -= y;
  if(x < 0) nope();
  if(x % 2 != 0) nope();
  puts("Yes");
  return 0;
}