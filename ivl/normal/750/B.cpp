#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << setw(3) << setfill('0') << __LINE__ << ": " << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

void no(){cout << "NO" << endl; exit(0);}

int main(){
  ios_base::sync_with_stdio(false);

  int n; cin >> n;
  int h = +10000;
  REP(ttt,n){
    int tmp; cin >> tmp;
    string com; cin >> com;
    if (h == +10000 && com != "South") no();
    if (h == -10000 && com != "North") no();
    if (com == "South") h -= tmp;
    if (com == "North") h += tmp;
    if (h > +10000 || h < -10000) no();
  }
  if (h != +10000) no();
  cout << "YES" << endl;

  return 0;
}