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
typedef pair<int, int> pii;

int main(){
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  set<string> sa, sb, sab;
  REP(i,n){string s; cin >> s; sa.insert(s);}
  REP(i,m){string s; cin >> s; sb.insert(s); if (sa.count(s)) sab.insert(s);}

  int a = (int)sa.size();
  int b = (int)sb.size();
  int ab = (int)sab.size();
  a -= ab;
  b -= ab;

  string A = "YES";
  string B = "NO";
  while (true){
    if (ab) --ab;
    else if (a) --a;
    else {cout << B << endl; return 0;}
    swap(a, b), swap(A, B);
  }
  
  return 0;
}