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
typedef pair<int, int> pii;

int n;
int type[10];
/*
  0 -> x
  1 -> !x
  2 -> false
  3 -> true
 */

int main(){
  ios_base::sync_with_stdio(false);

  cin >> n;
  REP(blatruc,n){
    char c;
    int x;
    cin >> c >> x;
    bitset<10> b(x);
    if (c == '|'){
      REP(i,10)
	if (b[i] == 1)
	  type[i] = 3;
    }
    if (c == '&'){
      REP(i,10)
	if (b[i] == 0)
	  type[i] = 2;
    }
    if (c == '^'){
      REP(i,10)
	if (b[i] == 1)
	  type[i] ^= 1;
    }
  }

  int And = (1 << 10)-1, Or = 0, Xor = 0;
  REP(i,10)
    if (type[i] == 1) Xor += (1 << i);
    else if (type[i] == 2) And -= (1 << i);
    else if (type[i] == 3) Or += (1 << i);

  cout << 3 << endl;
  cout << "&" << " " << And << endl;
  cout << "|" << " " << Or  << endl;
  cout << "^" << " " << Xor << endl;

  return 0;
}