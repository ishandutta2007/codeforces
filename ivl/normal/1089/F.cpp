#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)

#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

void imp(){cout << "NO" << endl; exit(0);}

int n;

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  int p = 0;
  for (int i = 2; i*i <= n; ++i)
    if (n%i == 0){
      p = i;
      break;
    }

  if (p == 0) imp();

  int a = 1, b = n;
  while (b%p == 0) b /= p, a *= p;

  if (b == 1) imp();

  if (a > b) swap(a, b);
  int x = (n-1) / b;
  int y = (n-1) - x * b;
  while (y%a != 0){
    --x;
    y += b;
  } y /= a;

  cout << "YES" << endl;
  cout << 2 << endl;
  cout << x << " " << a << endl;
  cout << y << " " << b << endl;

  return 0;
}