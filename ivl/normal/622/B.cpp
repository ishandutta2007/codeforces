#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define ll long long
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

int main(){
  int h, m, a;
  scanf("%d:%d%d", &h, &m, &a);
  m += a;
  h += m/60, m %= 60;
  h %= 24;
  printf("%02d:%02d\n", h, m);
  return 0;
}