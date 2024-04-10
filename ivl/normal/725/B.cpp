#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int f(char c){
  if (c == 'f') return 0;
  if (c == 'e') return 1;
  if (c == 'd') return 2;
  if (c == 'a') return 3;
  if (c == 'b') return 4;
  return 5;
}

int main(){
  ios_base::sync_with_stdio(false);

  ll n;
  char c;
  cin >> n >> c;

  -- n;
  ll sol = 1;
  sol += n / 4 * (6 + 1 + 6 + 3);
  n %= 4;
  ++n;

  if (n == 1) cout << sol + f(c) << endl;
  else if (n == 3) cout << sol + f(c) << endl;
  else if (n == 2) cout << sol + f(c) + 6 + 1 << endl;
  else cout << sol + f(c) + 6 + 1 << endl;
  
  return 0;
}