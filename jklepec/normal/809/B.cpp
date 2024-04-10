#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

int find_first(int n) {
  int lo = 1, hi = n;

  while(lo < hi) {
    int mid = (lo + hi) >> 1;

    cout << 1 _ mid _ mid + 1 << endl;
    string s; cin >> s;

    if(s == "TAK") {
      hi = mid;
    }
    else {
      lo = mid + 1;
    }
  }

  return lo;
}

int try_up(int x, int n) {
  if(x == n)
    return -1;

  int lo = x + 1, hi = n;
  while(lo < hi) {
    int mid = (lo + hi) >> 1;

    cout << 1 _ mid + 1 _ mid << endl;
    string s; cin >> s;

    if(s == "TAK") {
      lo = mid + 1;
    }
    else {
      hi = mid;
    }
  }

  cout << 1 _ lo _ x << endl;
  string s; cin >> s;

  if(s == "TAK")
    return lo;
  return -1;
}

int try_down(int x) {
  int lo = 1, hi = x - 1;
  while(lo < hi) {
    int mid = (lo + hi) >> 1;

    cout << 1 _ mid _ mid + 1 << endl;
    string s; cin >> s;

    if(s == "TAK") {
      hi = mid;
    }
    else {
      lo = mid + 1;
    }
  }

  return lo;
}

int main() {
  int n, k; cin >> n >> k;

  int x = find_first(n);
  int y = try_up(x, n);
  if(y != -1) {
    cout << 2 _ x _ y;
  }
  else {
    cout << 2 _ x _ try_down(x);
  }
  cout << endl;
}