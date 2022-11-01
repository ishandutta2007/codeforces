#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)

using namespace std;

void imp(){cout << -1 << endl; exit(0);}

int n;
string s;
int x, y;

bool check(int len){
  int xx = x, yy = y;
  auto rem = [&xx, &yy](char c){
    if (c == 'U') --yy;
    if (c == 'D') ++yy;
    if (c == 'R') --xx;
    if (c == 'L') ++xx;
  };
  auto add = [&xx, &yy](char c){
    if (c == 'U') ++yy;
    if (c == 'D') --yy;
    if (c == 'R') ++xx;
    if (c == 'L') --xx;
  };
  
  FOR(i,len,n) rem(s[i]);
  REP(i,n-len)
    if (abs(xx) + abs(yy) <= len) return true;
    else rem(s[i]), add(s[i+len]);

  return abs(xx) + abs(yy) <= len;
}

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n >> s >> x >> y;
  if (n < abs(x) + abs(y)) imp();
  if (n%2 != abs(x+y)%2) imp();

  int lo = 0, hi = n, mid;
  while (lo != hi){
    mid = (lo+hi)/2;
    if (check(mid)) hi = mid;
    else lo = mid+1;
  }

  cout << lo << endl;

  return 0;
}