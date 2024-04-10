#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " = " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main(){

  string s;
  cin >> s;
  for (auto c : s){
    int delta = 256 - c;
    for (auto t : {20, 4, 1})
      while (delta > t){
	REP(i,t) cout << ".X";
	cout << string(60-2*t, '.') << endl;
	cout << string(60, '.') << endl;
	delta -= t;
      }
    assert(delta == 1);
    cout << "X" << string(59, '.') << endl;
    cout << "X" << string(59, '.') << endl;
    cout << string(60, '.') << endl;
    delta = c + 1;
    for (auto t : {20, 4, 1})
      while (delta > t){
	REP(i,t) cout << ".X";
	cout << string(60-2*t, '.') << endl;
	cout << string(60, '.') << endl;
	delta -= t;
      }        
  }

  return 0;
}