#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define pb push_back

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;

int main(){
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;
  int a = s[0] == 'a' || s[0] == 'h';
  int b = s[1] == '1' || s[1] == '8';
  cout << (3-a)*(3-b)-1 << endl;
  
  return 0;
}