#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define ll long long
#define pb push_back
#define pii pair < int, int >
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

char f(char a, char b){
  if (a != 'a' && b != 'a') return 'a';
  if (a != 'b' && b != 'b') return 'b';
  return 'c';
}

int main(){
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;

  for (int i = 0, j = 0; i < (int)s.size(); i = j){
    while (j < (int)s.size() && s[i] == s[j]) ++j;
    for (int k = i+1; k < j; k += 2){
      if (k+1 != j || k+1 == (int)s.size())
	s[k] = f(s[k], s[k]);
      else s[k] = f(s[k], s[k+1]);
    }
  } cout << s << endl;
  
  return 0;
}