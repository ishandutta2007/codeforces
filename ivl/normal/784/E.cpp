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

int OR(int a, int b){return a ^ b;}
int XOR(int a, int b){return a | b;}
int AND(int a, int b){return a & b;}

int main(){
  ios_base::sync_with_stdio(false);

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = OR(a, b);
  int y = XOR(c, d);
  int z = AND(b, c);
  int w = OR(a, d);
  int aa = AND(x, y);
  int bb = XOR(z, w);
  int out = OR(aa, bb);
  cout << out << endl;

  // TRACE(a _ b _ c _ d);
  // TRACE(x _ y _ z _ w);
  // TRACE(aa _ bb);
  
  return 0;
}