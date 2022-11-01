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

string s;
int all[26][5005];
int M[26][26][5005];

int main(){
  ios_base::sync_with_stdio(false);

  cin >> s;
  int n = (int)s.size();

  REP(i,n) REP(j,n)
    ++M[s[i]-'a'][s[j]-'a'][(j-i+n)%n];

  REP(i,n){
    bitset<5005> bit;
    REP(j,n)
      if (M[s[i]-'a'][s[j]-'a'][(j-i+n)%n] == 1)
	++all[s[i]-'a'][(j-i+n)%n];
  }

  int cnt = 0;
  REP(i,26){
    int maks = 0;
    REP(j,5005) maks = max(maks, all[i][j]);
    cnt += maks;
  } cout << (double)cnt / n << endl;

  return 0;
}