#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " _ " << x << endl
#define _ << " _ " <<

using namespace std;

int main(){

  int h1, h2;
  int a, b;
  cin >> h1 >> h2;
  cin >> a >> b;
  h1 += a*8;
  a *= 12, b *= 12;

  if (a-b < 0 && h1 < h2){cout << -1 << endl; return 0;}

  int cnt = 0;
  for (; h1 < h2 && cnt < 1000000; ++cnt, h1 += a-b);
  if (cnt == 1000000) cnt = -1;
  cout << cnt << endl;
  
  return 0;
}